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
    public partial class Form2 : Form
    {
        public General General { get => generalBindingSource.Current as General; }
        public Form2(General general)
        {
            InitializeComponent();
            generalBindingSource.DataSource = general;
        }

        private void btnAddPerson_Click(object sender, EventArgs e)
        {
            
            using (var form = new Form3())
            {
                if (form.ShowDialog() != DialogResult.OK) return;
                General.Person = form.Person;
                generalBindingSource.ResetBindings(false);
            }
            
        }

        private void btnAddAdress_Click(object sender, EventArgs e)
        {
            using (var form = new Form5())
            { 
                /* if (General.Adress == null) return;
                else Form6.Adress = General.Adress;*/

                if (form.ShowDialog() != DialogResult.OK) return;
                General.Adress = form.Adress;
                generalBindingSource.ResetBindings(false);
                /*var adress = new Adress();
            if (!(sender is Button btn && btn.Tag is String op && op == "new"))
                if (Adress == null) return;
                else adress= Adress;
            using (var form = new Form6(adress))
                if (form.ShowDialog() == DialogResult.OK) 
            //AdressList.Add(adress);
            adressBindingSource.ResetBindings(false);
             */
            }
        }

        private void btnAddPhone_Click(object sender, EventArgs e)
        {
            using (var form = new Form7())
            {
                if (form.ShowDialog() != DialogResult.OK) return;
                General.Phone = form.Phone;
                generalBindingSource.ResetBindings(false);
            }
        }
    }
}
