using AngleSharp.Html.Parser;
using System;
using System.Net.Http;
using System.Threading;
using System.Threading.Tasks;

namespace DEditor
{
    internal class ParserWorker<T> where T : class
    {
        readonly HttpClient client;
        //readonly String url;
        IParser<T> parser;
        IParserSettings settings;
        Boolean isActive;
        public IParser<T> Parser { get => parser; set => parser = value; }
        public IParserSettings Settings { get => settings; set => settings = value; }
        public Boolean IsActive => isActive;
        public event Action<object, T> OnNewData;
        public event Action<object> OnComplete;

        public ParserWorker(IParser<T> parser) => this.parser = parser;

        public ParserWorker(IParser<T> parser, IParserSettings settings) : this(parser)
        {
            this.settings = settings;
            client = new HttpClient();
            //url = $"{settings.BaseURL}/{settings.Prefix}/";
            //client.BaseAddress = new Uri(settings.BaseURL);
        }

        public void Start()
        {
            isActive = true;
            Do();//Worker();
        }

        public void Abort() => isActive = false;

        private async void DoAsunc()
        {
            if (!isActive)
            {
                OnComplete?.Invoke(this);
                return;
            }
            var source = await GetSourceByPageId();
            var domParser = new HtmlParser();
            //var document = await domParser.ParseAsync(source);
            var document = await domParser.ParseDocumentAsync(source, new CancellationToken(false));
            var result = parser.Parse(document);
            OnNewData?.Invoke(this, result);
            OnComplete?.Invoke(this);
            isActive = false;
            
            //for (var i = settings.StartPoint; i<=settings.EndPoint; i++)
            //{
            //    if (!isActive)
            //    {
            //        OnComplete?.Invoke(this);
            //        return;
            //    }
            //    var source = await GetSourceByPageId(i);
            //    var domParser = new HtmlParser();
            //    //var document = await domParser.ParseAsync(source);
            //    var document = await domParser.ParseDocumentAsync(source, new CancellationToken(true));
            //    var result = parser.Parse(document);
            //    OnNewData?.Invoke(this, result);
            //}
            //OnComplete?.Invoke(this);
            //isActive = false;
        }

        private async void Do()
        {
            if (!isActive)
            {
                OnComplete?.Invoke(this);
                return;
            }
            //var source = await GetSourceByPageId();

            var response = await client.GetAsync("https://farmasi.ua");//currentURL);
            var source = String.Empty;
            if (response != null && response.StatusCode == System.Net.HttpStatusCode.OK)
                source = await response.Content.ReadAsStringAsync();
            
            var domParser = new HtmlParser();
            //var document = await domParser.ParseAsync(source);
            var document = domParser.ParseDocument(source);

            var items = document.QuerySelectorAll("div");//.GetElementsByClassName("categoryHeader");//.Select(i => i.QuerySelector("a"));
            items = document.QuerySelectorAll("a");

            var result = parser.Parse(document);
            OnNewData?.Invoke(this, result);
            OnComplete?.Invoke(this);
            isActive = false;
        }

        //public async Task<String> GetSourceByPageId(Int32 id)
        //{
        //    var currentURL = url.Replace("{CurrentId}", id.ToString());
        //    var response = await client.GetAsync(currentURL);
        //    var sourse = String.Empty;
        //    if (response != null && response.StatusCode == System.Net.HttpStatusCode.OK)
        //        sourse = await response.Content.ReadAsStringAsync();
        //    return sourse;
        //}

        public async Task<String> GetSourceByPageId()
        {
            //var currentURL = url.Replace("{CurrentId}", id.ToString());
            var response = await client.GetAsync("farmasi.ua");//currentURL);
            var sourse = String.Empty;
            if (response != null && response.StatusCode == System.Net.HttpStatusCode.OK)
                sourse = await response.Content.ReadAsStringAsync();
            return sourse;
        }
    }
}
