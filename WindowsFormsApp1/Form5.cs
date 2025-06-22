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
    public partial class Form5 : Form
    {
        public  List<Adress> AdressList = new List<Adress>();
        public Adress Adress {get => adressBindingSource.Current as  Adress; }
        public Form5()
        {
            InitializeComponent();
            adressBindingSource.DataSource = AdressList;
        }
        
        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            var adress = new Adress();
            if (!(sender is Button btn && btn.Tag is String op && op == "new"))
                if (Adress == null) return;
                else adress= Adress;
            using (var form = new Form6(adress))
                if (form.ShowDialog() == DialogResult.OK) 
            //AdressList.Add(adress);
            adressBindingSource.ResetBindings(false);
        }
    }
}
