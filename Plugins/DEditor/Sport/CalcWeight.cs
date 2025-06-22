using System;
using System.ComponentModel;

namespace DEditor.Sport
{
    internal class CalcWeight
    {
        [DisplayName("Вес")]
        public Double Weight { get; set; }
        [DisplayName("1 подход")]
        public Int32 FirsttValue { get; set; }
        [DisplayName("2 подход")]
        public Int32 SecondValue { get; set; }
        [DisplayName("3 подход")]
        public Int32 ThirdValue { get; set; }
        [DisplayName("4 подход")]
        public Int32 FourthValue { get; set; }
        [DisplayName("5 подход")]
        public Int32 FifthValue { get; set; }
    }
}
