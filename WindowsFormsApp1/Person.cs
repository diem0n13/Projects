using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    public class Person
    {
        [DisplayName("Фамилия")]
        public string FirstName { get; set; }
        [DisplayName("Имя")]
        public string LastName { get; set; }
        [DisplayName("Отчество")]
        public string SerName { get; set; }
        [DisplayName("Пол")]
        public string Gender { get; set; }
        [DisplayName("Год рождения")]
        public string BithDay { get; set; }

        public override string ToString()
        {
            return FirstName + " " + LastName + " " + SerName;
        }
    }
}
