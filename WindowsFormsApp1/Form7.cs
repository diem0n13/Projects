using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form7 : Form
    {
        public  List<Phone> PhoneList = new List<Phone>();
        public Phone Phone {get => phoneBindingSource.Current as Phone; }
        public Form7()
        {
            InitializeComponent();
            phoneBindingSource.DataSource = PhoneList;
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            var phone = new Phone();
            if (!(sender is Button btn && btn.Tag is String op && op == "new"))
                if (Phone == null) return;
                else phone = Phone;
            using (var form = new Form8(phone))
                if (form.ShowDialog() == DialogResult.OK) 
                    //PhoneList.Add(phone);
           phoneBindingSource.ResetBindings(false);
        }
    }
}
