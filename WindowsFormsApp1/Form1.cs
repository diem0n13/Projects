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
    public partial class Form1 : Form
    {
        public  List<General> GeneralsList { get; set; } = new List<General>();

        public General General { get => generalBindingSource.Current as General; } 
        
        public Form1()
        {
            InitializeComponent();
            generalBindingSource.DataSource = GeneralsList;
        }

        private void toolStripButtonAdd_Click(object sender, EventArgs e)
        {
            var general = new General();

            using (var form = new Form2(general))
                if (form.ShowDialog() == DialogResult.OK )
                    GeneralsList.Add(general);
            generalBindingSource.ResetBindings(false);
        }

        private void toolStripButtonEdit_Click(object sender, EventArgs e)
        {
            var general = new General();
            if (!(sender is Button btn && btn.Tag is String op && op == "edit"))
                if (General == null) return;
                else general= General;
            using (var form = new Form2(general))
                if (form.ShowDialog() == DialogResult.OK)
                    //GeneralsList.Add(general);
            generalBindingSource.ResetBindings(false);
        }
    }
}
