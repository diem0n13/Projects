using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Xml;

namespace ConsoleEditor
{
    internal class Program
    {
        static void Main(string[] args)
        {
            if (args.Length < 2)
            {
                Console.WriteLine("Error, absent arguments!");
                return;
            }
            foreach (String path in args)
            {
                var str = Path.GetFullPath(path);
                if (String.IsNullOrEmpty(str))
                {
                    Console.WriteLine("Error, incorrect file path!");
                    return;
                }
            }
            if (!File.Exists(args[0]))
            {
                Console.WriteLine("Error, input file does not exist!");
                return;
            }
            switch (args.Length)
            {
                case 2:
                    var captions = new Dictionary<String, String>();
                    ChangeData(args[0], null, captions);
                    if (File.Exists(args[1])) 
                    {
                        var existCaptions = LoadFile(args[1]);
                        foreach(var cap in captions)
                        {
                            var eKey = String.Empty;
                            foreach (var eCap in existCaptions)
                                if (cap.Key.Equals(eCap.Key)) 
                                {
                                    eKey = eCap.Key;
                                    captions[eKey] = existCaptions[eKey];
                                    break;
                                }
                            existCaptions.Remove(eKey);
                        }
                        File.Delete(args[1]);
                    }
                    CreateFile(args[1], captions);
                    Console.WriteLine("Headers is created!");
                    break;
                case 3:
                    ChangeData(args[0], args[2], LoadFile(args[1]));
                    Console.WriteLine("Data is changed!");
                    break;
                default:
                    Console.WriteLine("Error!");
                    break;
            }
        }

        private static void CreateFile(String path, Dictionary<String, String> captions)
        {
            using (FileStream fstream = new FileStream(path, FileMode.OpenOrCreate))
            {
                byte[] info = new UTF8Encoding(true).GetBytes("[translate]\n");
                fstream.Write(info, 0, info.Length);
                foreach (var item in captions)
                {
                    var value = item.Key + " = " + item.Value + "\n";
                    info = new UTF8Encoding(true).GetBytes(value);
                    fstream.Write(info, 0, info.Length);
                }
            }
        }

        private static Dictionary<String, String> LoadFile(String path)
        {
            var captions = new Dictionary<String, String>();
            if (!File.Exists(path)) return null;
            using (FileStream fstream = new FileStream(path, FileMode.OpenOrCreate))
            {
                var bytes = new byte[fstream.Length];//info = new UTF8Encoding(true).GetBytes(value);
                var numBytesToRead = (int)fstream.Length;
                var n = 0;
                for (var i = 0; fstream.Length > i; i += n, numBytesToRead -= n)
                {
                    n = fstream.Read(bytes, i, numBytesToRead);
                    if (n == 0) break;
                }
                var Values = Regex.Split(Encoding.UTF8.GetString(bytes), "\n");
                foreach (var item in Values)
                {
                    var ss = Regex.Split(item, " = ");
                    if (ss.Length < 2) continue;
                    captions.Add(ss[0], ss[1]);
                }
            }
            return captions;
        }

        private static void ChangeData(String loadPath, String savePath, Dictionary<String, String> captions)
        {
            var xDoc = new XmlDocument();
            xDoc.Load(loadPath);
            var ToolManager = xDoc.DocumentElement;
            if (ToolManager == null) return;
            foreach (XmlElement Tabs in ToolManager)
            {
                if (Tabs.Name != "Tabs") continue;
                foreach (XmlElement Tab in Tabs)
                {
                    if(String.IsNullOrEmpty(savePath))
                        AddCaption(Tab, captions);
                    else
                        ChangeAttribute(Tab, captions);
                    foreach (XmlElement Groups in Tab)
                        foreach (XmlElement Group in Groups)
                        {
                            if (String.IsNullOrEmpty(savePath))
                                AddCaption(Group, captions);
                            else
                                ChangeAttribute(Group, captions);
                        }
                }
            }
            if (!String.IsNullOrEmpty(savePath))
                xDoc.Save(savePath);
        }

        private static void AddCaption(XmlElement elem, Dictionary<String, String> dic)
        {
            var caption = elem.GetAttribute("Caption");
            if (!String.IsNullOrEmpty(caption) && !dic.ContainsKey(caption))
                dic.Add(caption, "");
        }
        private static void ChangeAttribute(XmlElement elem, Dictionary<String, String> dic)
        {
            var key = elem.GetAttribute("Caption");
            if (key is String && dic.ContainsKey(key))
                elem.SetAttribute("Caption", dic[key]);
        }

        #region UnUsed Methods
        private Dictionary<String, String> GetData(String path)
        {
            var captions = new Dictionary<String, String>();
            var xDoc = new XmlDocument();
            xDoc.Load(path);
            var ToolManager = xDoc.DocumentElement;
            if (ToolManager == null) return null;
            foreach (XmlElement Tabs in ToolManager)
            {
                if (Tabs.Name != "Tabs") continue;
                foreach (XmlElement Tab in Tabs)
                {
                    AddCaption(Tab, captions);
                    foreach (XmlElement Groups in Tab)
                        foreach (XmlElement Group in Groups)
                            AddCaption(Group, captions);
                }
            }
            return captions;
        }

        private void SetData(String path, Dictionary<String, String> captions)
        {
            var xDoc = new XmlDocument();
            xDoc.Load(path);
            var ToolManager = xDoc.DocumentElement;
            if (ToolManager == null) return;
            foreach (XmlElement Tabs in ToolManager)
            {
                if (Tabs.Name != "Tabs") continue;
                foreach (XmlElement Tab in Tabs)
                {
                    ChangeAttribute(Tab, captions);
                    foreach (XmlElement Groups in Tab)
                        foreach (XmlElement Group in Groups)
                            ChangeAttribute(Group, captions);
                }
            }
            xDoc.Save(path);
        }

        private void CreateNewFile(String path)
        {
            var settings = new XmlWriterSettings();
            settings.Indent = true;
            using (var writer = XmlWriter.Create(Path.Combine(Path.GetDirectoryName(path), "output.xml"), settings))
            {
                var xDoc = new XmlDocument();
                xDoc.Load(path);
                var ToolManager = xDoc.DocumentElement;
                if (ToolManager == null) return;
                foreach (XmlElement Tabs in ToolManager)
                {
                    if (Tabs.Name == "Tabs")
                    {
                        writer.WriteStartElement("Tabs");
                        foreach (XmlElement Tab in Tabs)
                        {
                            writer.WriteStartElement("Tab");
                            writer.WriteAttributeString("Key", Tab.GetAttribute("Key"));
                            writer.WriteAttributeString("Caption", Tab.GetAttribute("Caption"));
                            foreach (XmlElement Groups in Tab)
                            {
                                writer.WriteStartElement("Groups");
                                foreach (XmlElement Group in Groups)
                                {
                                    writer.WriteStartElement("Group");
                                    writer.WriteAttributeString("Key", Group.GetAttribute("Key"));
                                    writer.WriteAttributeString("Caption", Group.GetAttribute("Caption"));
                                    writer.WriteEndElement();
                                }
                                writer.WriteEndElement();
                            }
                            writer.WriteEndElement();
                        }
                        writer.WriteEndElement();
                    }
                }
            }
        }

        private void CreateFile(String path)
        {
            var settingsReader = new XmlReaderSettings();
            using (var reader = XmlReader.Create(path, settingsReader))
            {
                var settingsWriter = new XmlWriterSettings();
                settingsWriter.Indent = true;
                using (var writer = XmlWriter.Create(Path.Combine(Path.GetDirectoryName(path), "output.xml"), settingsWriter))
                {
                    while (reader.Read())
                    {
                        var key = reader.GetAttribute("Key");
                        var caption = reader.GetAttribute("Caption");

                        //if (reader.IsStartElement() && reader.Name == "Tabs")
                    }
                }
            }
        }

        private Dictionary<String, String> GetData2(String path)
        {
            var captions = new Dictionary<String, String>();
            var settingsReader = new XmlReaderSettings();
            using (var reader = XmlReader.Create(path, settingsReader))
            {
                while (reader.Read())
                {
                    if (!reader.IsStartElement()) continue;
                    var caption = reader.GetAttribute("Caption");
                    if (!String.IsNullOrEmpty(caption) && !captions.ContainsKey(caption))
                        captions.Add(caption, "");
                }
            }
            return captions;
        }
        #endregion
    }
}
