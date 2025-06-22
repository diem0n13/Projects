using DEditor.Sport;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DEditor
{
    public partial class fmCalcWeight : Form
    {
        private List<CalcWeight> calcWeights = new List<CalcWeight>();

        public fmCalcWeight()
        {
            InitializeComponent();
            //calcWeightBindingSource.DataSource = calcWeights;
            //calcWeightBindingSource.ResetBindings(false);
        }

        private void bindingNavigatorAddNewItem_Click(object sender, EventArgs e)
        {
            calcWeights.Add(new CalcWeight());

        }
    }
}
