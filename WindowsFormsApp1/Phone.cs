using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    public class Phone
    {
        [DisplayName("Номер телефона")] 
        public string PhoneNumber { get; set; }
        [DisplayName("Тип телефона")]
        public string KindPhone { get; set; }

        public override string ToString()
        {
            return PhoneNumber;
        }
    }
}
