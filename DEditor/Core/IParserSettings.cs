using System;

namespace DEditor
{
    internal interface IParserSettings
    {
        String BaseURL { get; set; }
        String Prefix { get; set; }
        Int32 StartPoint { get; set; }
        Int32 EndPoint { get; set; }
    }
}
