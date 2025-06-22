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
    
    public partial class Form3 : Form
    {
        //public List<Person> PersonList = new List<Person>();
        //public General General = new General();
        public Person Person  { get => personBindingSource.Current as Person; }
        public Form3()
        {
            InitializeComponent();
            personBindingSource.DataSource = WFContainer.Instance.Persons;
            
        }
        
        private void toolStripButton1_Click(object sender, EventArgs e)
        {
        var person =  new Person();
        var mNew = (sender is ToolStripButton btn && btn.Tag is String op && op == "new");
        if (!mNew)
            if (Person == null) return;
            else person = Person;
        using (var form = new Form4(person))
            if (form.ShowDialog() == DialogResult.OK)
                if (mNew) WFContainer.Instance.Persons.Add(person);

        personBindingSource.ResetBindings(false);

        }
    }
}
