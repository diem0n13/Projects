using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;
using System.Xml;

namespace DEditor
{
    public partial class fmDEditor : Form
    {
        ParserWorker<String[]> parserWorker;

        public fmDEditor()
        {
            parserWorker = new ParserWorker<string[]>(new Farma(), new FarmaSettings());
            InitializeComponent();
            parserWorker.OnComplete += ParserWorker_OnComplete;
            parserWorker.OnNewData += ParserWorker_OnNewData;
        }

        private void ParserWorker_OnNewData(object arg1, string[] arg2)
        {
            teSearch.Clear();
            var txt = String.Empty;
            foreach (var s in arg2)
                txt += s + "\r\n";
            teSearch.Text = txt;
        }

        private void ParserWorker_OnComplete(object obj)
        {
            MessageBox.Show("All Done!", "", MessageBoxButtons.OK);
        }

        private void Convert_Click(object sender, EventArgs e)
        {
            var input = teInput.Text;
            if (String.IsNullOrEmpty(input) || String.IsNullOrEmpty(teOutput.Text))
            {
                MessageBox.Show("Error, incorrect file path!", "Error", MessageBoxButtons.OK);
                return;
            }
            if (!File.Exists(input))
            {
                MessageBox.Show("Error, input file does not exist!", "Error", MessageBoxButtons.OK);
                return;
            }
            var outputPath = Path.Combine(Path.GetDirectoryName(input), teOutput.Text + ".csv");
            if (File.Exists(outputPath))
            {
                if (MessageBox.Show("Error, output file is exist! " +
                    "Delete file and create new?", "Error", MessageBoxButtons.YesNo) == DialogResult.Yes)
                    File.Delete(outputPath);
                else
                    return;
            }
            using (var sw = new StreamWriter(outputPath, true, new UTF8Encoding(true)))
            {
                using (var sr = new StreamReader(input))
                {
                    var line = String.Empty;
                    var header = String.Empty;
                    var mainHeader = String.Empty;
                    var price = String.Empty;
                    var id = String.Empty;
                    var name = String.Empty;
                    var count = 0;
                    while ((line = sr.ReadLine()) != null)
                    {
                        if (String.IsNullOrEmpty(line))
                        {
                            count = 0;
                            continue;
                        }
                        if (line.Contains("//"))
                        {
                            mainHeader = line.Trim('/');
                            count = 0;
                            continue;
                        }
                        if (line.Contains(".."))
                        {
                            header = line.Trim('.');
                            count = 0;
                            continue;
                        }
                        if (count == 1)//(Int32.TryParse(line.Trim(' '), out Int32 ID))
                        {
                            id = line.Trim(' ');
                            count = 2;
                            continue;
                        }
                        if (line.Contains("₴"))
                        {
                            price = line.Trim(' ', '₴') + ".00";
                            sw.WriteLine("{0};{1};{2};;;;{3};;;;;;{4};;;", mainHeader, name, id, price, header);
                            //count = 3;
                            continue;
                        }
                        if (count == 0)
                        {
                            name = line;
                            count = 1;
                        }
                    }
                }
            }
            MessageBox.Show("Is Done!", "", MessageBoxButtons.OK);
        }
        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnAddInput_Click(object sender, EventArgs e)
        {
            var openDialg = new OpenFileDialog();
            openDialg.ShowDialog();
            //if (String.IsNullOrEmpty(openDialg.FileName)) return;
            teInput.Text = openDialg.FileName;
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            var text = String.Empty;
            var indexes = new HashSet<Int32>();
            var jndexes = new HashSet<Int32>();
            var rows = new List<String>();
            using (var sr = new StreamReader(teInput.Text, Encoding.GetEncoding(1251)))
            {
                var line = String.Empty;
                while ((line = sr.ReadLine()) != null)
                    rows.Add(line);
            }
            using (var sw = new StreamWriter(Path.Combine(Path.GetDirectoryName(teInput.Text), teOutput.Text + ".csv"), true, new UTF8Encoding(true)))
            {
                var count = 0;
                for (var i = 0; rows.Count > i; i++)
                {
                    var row = Regex.Split(rows[i], ";");
                    //if (row.Length < 16)//check csv
                    //{
                    //    MessageBox.Show("Error!", "Error", MessageBoxButtons.OK);
                    //    return;
                    //}

                    for (var j = 0; rows.Count > j; j++)
                    {
                        if (i == j) continue;
                        if (rows[j].Contains(row[2]) && !(indexes.Contains(i) || indexes.Contains(j)))
                        {
                            indexes.Add(i);
                            indexes.Add(j);
                            jndexes.Add(j);
                            count++;
                            text += count + row[0] + " " + row[1] + " " + row[2] + " " + row[7] + " " + i + " & " + j + "\r\n";

                            //text += row[0] + " " + row[1] + " " + row[2] + " " + row[7] + " " + row[13] + i + "&" + j + "\r\n";
                        }
                        //if (!(indexes.Contains(i) || indexes.Contains(j)))
                        //    sw.WriteLine("{0};{1};{2};;;;{3};;;;;;;;;", row[0], row[1], row[2].Trim(' '), row[6]);
                    }
                    //text += mainHeader + ";" + name + ";" + id + ";;;;" + price + ";;;;;;" + header + ";;;\r\n";
                }
                teSearch.Clear();
                teSearch.Text = text;
                MessageBox.Show("Is Done!", "", MessageBoxButtons.OK);
                for (var i = 0; rows.Count > i; i++)
                {
                    var rowz = Regex.Split(rows[i], ";");
                    if (jndexes.Contains(i)) continue;
                        sw.WriteLine("{0};{1};{2};;;;{3};;;;;;;;;", rowz[0], rowz[1], rowz[2].Trim(' '), rowz[6]);
                }
            }
        }

        private void btnFormatting_Click(object sender, EventArgs e)
        {
            var outputPath = Path.Combine(Path.GetDirectoryName(teInput.Text), teOutput.Text + ".csv");
            if (File.Exists(outputPath))
            {
                if (MessageBox.Show("Error, output file is exist! " +
                    "Delete file and create new?", "Error", MessageBoxButtons.YesNo) == DialogResult.Yes)
                    File.Delete(outputPath);
                else
                    return;
            }
            using (var sr = new StreamReader(teInput.Text, Encoding.GetEncoding(1251)))
            {
                using (var sw = new StreamWriter(outputPath, true, new UTF8Encoding(true)))
                {
                    var line = String.Empty;
                    var price = String.Empty;
                    var id = String.Empty;
                    while ((line = sr.ReadLine()) != null)
                    {
                        var row = Regex.Split(line, ";");

                        if (String.IsNullOrEmpty(line)) continue;
                        id = row[2].Trim(' ');
                        if (row[6].Contains(".00"))
                            price = row[6].Trim(' ');
                        else
                            price = row[6].Trim(' ') + ".00";
                        sw.WriteLine("{0};{1};{2};;;;{3};;;;;;{4};;;", row[0], row[1], id, price, row[13]);
                    }
                }
            }
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            //parserWorker.Settings = new FarmaSettings((Int32)numStart.Value, (Int32)numEnd.Value);
            parserWorker.Start();
        }

        private void btnEnd_Click(object sender, EventArgs e)
        {
            parserWorker.Abort();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            using (var form = new fmCalcWeight())
            {
                form.ShowDialog();
            }
        }
    }
}
