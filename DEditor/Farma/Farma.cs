using AngleSharp.Browser;
using AngleSharp.Dom;
using AngleSharp.Html.Dom;
using System;
using System.Collections.Generic;
using System.Linq;

namespace DEditor
{
    internal class Farma : IParser<String[]>
    {
        public String[] Parse(IHtmlDocument document)
        {
            var list = new List<String>();

            var itemz = document.QuerySelectorAll("div");//.GetElementsByClassName("categoryHeader");//.Select(i => i.QuerySelector("a"));
            itemz = document.QuerySelectorAll("a");
            //foreach (var itm in itemz)
            //{
            //    list.Add(itm.TextContent);
            //}

            var items = document.QuerySelectorAll("a").Where(i => i.ClassName != null && i.ClassName.Contains(""));
            foreach (var item in items)
                list.Add(item.TextContent);

            return list.ToArray();
        }
    }
    //internal class Farma : IParser<String[]>
    //{
    //    public String[] Parse(IHtmlDocument document)
    //    {
    //        var list = new List<String>();
    //        var items = document.QuerySelectorAll("a").Where(i => i.ClassName != null && i.ClassName.Contains(""));
    //        //.GetElementsByClassName

    //        foreach(var item in items)
    //            list.Add(item.TextContent);

    //        return list.ToArray();
    //    }
    //}
}
