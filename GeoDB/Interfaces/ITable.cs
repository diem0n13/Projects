using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GeoDB
{
    interface ITable
    {
        List<IRow> Rows { get; set; }
    }
}
