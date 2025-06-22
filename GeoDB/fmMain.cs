using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GeoDB
{
    public partial class fmMain : Form
    {
        public class ParentTable
        {
            public List<ParentRow> Rows { get; set; }
        }

        public class ChildTable
        {
            public ParentRow Row { get; set; }
            public List<ChildRow> Rows { get; set; }
        }

        public class ParentRow
        {
            public ChildTable ChildTable { get; set; }
            public List<ChildRow> Rows { get; set; }
        }

        public class ChildRow { }


        public fmMain()
        {
            InitializeComponent();
        }

        void GetData()
        {
            var parentTable = new ParentTable(); //some data

            // "Разворачивает" списки в один поток
            List<ChildRow> chRows = parentTable.Rows.SelectMany(r => r.Rows).ToList();

            // Добавляем дочерние ряды из ChildTable
            var chRows2 = parentTable.Rows.SelectMany(r => r.Rows.Concat(r.ChildTable?.Rows ?? new List<ChildRow>()));

            // Берём ещё и Row.Rows
            var chRows3 = parentTable.Rows.SelectMany(r => r.Rows.Concat(r.ChildTable?.Rows ?? new List<ChildRow>()).Concat(r.ChildTable?.Row?.Rows ?? new List<ChildRow>()));


            var Data = new Dictionary<ChildTable, List<ChildRow>>();
            
            var parentData = Data.Where(kvp => kvp.Key.Row != null).GroupBy(kvp => kvp.Key.Row)
                .ToDictionary(g => g.Key, g => g.SelectMany(kvp => kvp.Value).ToList());

            var Data2 = parentTable.Rows.ToDictionary(parentRow => parentRow, parentRow => parentRow.Rows
            .Concat(parentRow.ChildTable?.Rows ?? new List<ChildRow>())).ToList();
        }
    }
}
