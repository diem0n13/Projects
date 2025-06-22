using System;

namespace DEditor
{
    internal class FarmaSettings : IParserSettings
    {
        public FarmaSettings()
        {

        }
        public FarmaSettings(Int32 start, Int32 end)
        {
            StartPoint = start;
            EndPoint = end;
        }
        public String BaseURL { get; set; } = "https://farmasi.ua";
        /*https://farmasi.ua/products/dr-c-tuna/зволожувальна-серія-для-обличчя-aqua-20?cid=922d061c-7ba6-eb11-a310-005056010959*/
        public String Prefix { get; set; } //= "products{CurrentId}";
        public Int32 StartPoint { get; set; }
        public Int32 EndPoint { get; set; }
    }
}
