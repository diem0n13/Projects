using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    public class Adress
    {
        [DisplayName("Улица")]
        public string Street { get; set; }
        [DisplayName("Номер дома")]
        public string Building { get; set; }
        [DisplayName("Номер квартиры")]
        public string Flat { get; set; }

        public override string ToString()
        {
            return Street + " " + Building + "/" + Flat;
        }
    }
}
