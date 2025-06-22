using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    public class General
    {
        
        [DisplayName("ФИО")]
        public Person Person { get; set; } 

        [DisplayName("Адресс")]
        public Adress Adress { get; set; }

        [DisplayName("Телефон")]
        public Phone Phone { get; set; }

        [DisplayName("email")]
        public string Email { get; set; }

    }

    public class WFContainer
    {
        public List<Person> Persons = new List<Person>();
        //public List<Phone> Phones = new List<Phone>();
        //public List<Adress> Adresses = new List<Adress>();
        //public General General = new General();
        //public Person Person = new Person();
        public static WFContainer Instance { get; private set; } = new WFContainer();
        //public static WFContainer Instance;

        
    }
        

       
}
