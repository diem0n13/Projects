using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows.Forms;

namespace CreateFolder
{
    public partial class CreateFolder : Form
    {
        public CreateFolder()
        {
            InitializeComponent();
            var t =  new TimeCalc.TimeCalc();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnCreate_Click(object sender, EventArgs e)
        {
            Int32.TryParse(edQuantity.Text, out var count);
            new Creator(edPath.Text, edName.Text, count).Build();
        }

        private void btnAddPath_Click(object sender, EventArgs e)
        {
            var fDialog = new FolderBrowserDialog();
            if (fDialog.ShowDialog() == DialogResult.OK)
            {
                edPath.Text = fDialog.SelectedPath;
            }
        }
    }
}
