using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CreateFolder
{
    internal class Creator
    {
        private String _path { get; set; }
        private String Name { get; set; }
        private Int32 Quantity { get; set; }

        public Creator() { }
        public Creator(String path, String name, Int32 count) 
        {
            _path = path;
            Name = name;
            Quantity = count;
        }

        public void Build()
        {
            if (Quantity == 0)
            {
                MessageBox.Show("No Quantity");
                return;
            }
            if (String.IsNullOrEmpty(_path))
            {
                MessageBox.Show("No Path");
                return;
            }
            if (String.IsNullOrEmpty(Name))
            {
                MessageBox.Show("No Name");
                return;
            }

            var created = 0;
            var skipped = 0;

            for (int i = 1; i < Quantity; i++) 
            {
                var fullPath = Path.Combine(_path, Name + i.ToString());//String.Concat(File, ".txt")

                //if (File.Exists(fullPath))
                //{
                //    try
                //    {
                //        using (var f = File.Open(fullPath, FileMode.Open)) { }
                //    }
                //    catch
                //    {
                //        MessageBox.Show("FileIsBusy");
                //        return;
                //    }
                //}
                if (!Directory.Exists(fullPath))
                {
                    Directory.CreateDirectory(fullPath);
                    created++;
                    //MessageBox.Show($"The folder was created: {fullPath}");
                }
                else
                {
                    skipped++;
                    //MessageBox.Show("Error: the folder already exist");
                }
            }
            MessageBox.Show($"The folder was created: {created}, skipped: {skipped}");
        }
    }
}
