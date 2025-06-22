
using AngleSharp.Html.Dom;

namespace DEditor
{
    internal interface IParser<T> where T : class
    {
        T Parse(IHtmlDocument document);
    }
}
