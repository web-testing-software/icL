from pygments.lexer import RegexLexer, bygroups
from pygments.token import *

import re

__all__=['IclProLexer']

class IclProLexer(RegexLexer):
    name = 'IclPro'
    aliases = ['icL_Pro']
    filenames = ['*.icL', '*.icL-Pro']
    flags = re.MULTILINE | re.UNICODE

    tokens = {
        'root' : [
            (u'\\b(now|if|else|for|filter|range|exists|while|do|any|emit|emitter|slot|assert|listen|wait|jammer|switch|case)\\b', bygroups(Keyword)),
            (u'\\b(bool|int|double|string|list|element|set|item|object|void|regex|datetime|session|window|cookie|tab|document|file|query|database|dbmanager|js-file|code-(icl|js|sql)|handler|any|type)\\b', bygroups(Keyword.Type)),
            (u'\\b(icL|Log|Tab|Document|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|State|DB|Query|DBManager|Code|Signal|Datetime)\\b', bygroups(Name.Class)),
            (u'(\\\')(year|y|xPath|x|windows|window|width|visible|value|valid|url|typeName|typeId|tsv|title|texts?|teleport|tagName|tags?|tabs?|sum|sqrt2|source|silentMode|shift|session|selected|secure|second|scriptTimeout|screenshot|right|rects?|readOnly|rValue|quadratic|product|process|previous|pressTime|present|piDiv4|piDiv2|pi|path|partialLinkText|pageLoadTimeout|none|next|name|moveTime|month|minute|min|middle|max|log2e|log10e|ln2|ln10|linkText|link|linear|length|left|last|lValue|implicitTimeout|humanMode|httpOnly|hour|height|format|flashMode|first|expiry|enabled|empty|e|domain|document|day|current|cubic|ctrl|csv|css\\-\\w+|cssSelector|cookies|clickTime|clickable|capacity|bezier|attrs?\\-\\w+|alt|alert|2divSqrtPi|2divPi|1divSqrt2|1divPi)\\b', bygroups(Name, Name)),
            (u'(\\\'props?\\-)(wrap|willValidate|width|volume|videoWidth|videoHeight|valueAsNumber|value|validity|validationMessage|username|useMap|type|title|textLength|textContent|text|target|tagName|tHead|tFoot|tBodies|step|start|srclang|src|spellcheck|span|size|selectionStart|selectionEnd|selectionDirection|selectedOptions|selectedIndex|selected|seeking|search|scrollWidth|scrollTop|scrollLeft|scrollHeight|scope|rowSpan|rowIndex|reversed|required|rel|readyState|readOnly|protocol|previousElementSibling|preload|prefix|poster|position|port|playbackRate|placeholder|paused|pattern|pathname|password|parentElement|outerHTML|origin|options|offsetWidth|offsetTop|offsetParent|offsetLeft|offsetHeight|nodeValue|nodeType|nodeName|noValidate|noModule|nextElementSibling|networkState|naturalWidth|naturalHeight|name|muted|multiple|min|mediaGroup|media|maxLength|max|low|loop|localName|list|length|lastChild|lang|labels|label|kind|isMap|isContentEditable|isConnected|innerText|innerHTML|inert|index|indeterminate|id|httpEquiv|htmlFor|hreflang|href|hostname|host|high|hidden|height|hash|formTarget|formNoValidate|formMethod|formEnctype|formAction|form|firstChild|ended|enctype|encoding|elements|duration|draggable|download|disabled|disableRemotePlayback|dirName|dir|defer|defaultValue|defaultSelected|defaultPlaybackRate|defaultMuted|defaultChecked|default|dateTime|dataset|currentTime|currentSrc|crossOrigin|coords|controls|control|contentEditable|content|computedRole|computedName|complete|cols|colSpan|clientWidth|clientTop|clientLeft|clientHeight|className|cite|childNodes|checked|charset|cells|cellIndex|caption|baseURI|autoplay|autofocus|autocomplete|async|as|areas|alt|allowPaymentRequest|action|accessKeyLabel|accessKey|acceptCharset|accept|abbr)\\b', bygroups(Name, Name)),
            (u'(\\\')([\\w\\-]+)', bygroups(Punctuation, Name)),
            (u'(sql)({)', bygroups(Name.Function, Punctuation), 'main__1'),
            (u'(icl)(:pro)?({)', bygroups(Name.Function, Keyword.Pseudo, Punctuation)),
            (u'(\\.)(write|type|trim|toUpperCase|toUTC|toTimeZone|toPrev|toNext|toLowerCase|toLast|toFirst|tan|sync|switchToParent|switchToFrame|switchToDefault|switchTo|superClick|substring|state|stack|split|sort|sin|setup|setProcess|setAsUserScript|setAsPersistentUserScript|set|sendKeys|seek|secsTo|screenshot|runAsync|run|round|rightJustified|right|return|restoreProcess|restore|resetTime|replaceInStrings|replace|removeOne|removeLast|removeFirst|removeField|removeDuplicates|removeAt|removeAll|remove|refresh|radiansToDegrees|queryTags|queryTag|queryLinks|queryLink|queryByXPath|queryAllByXPath|queryAll|query|process|previous|prev|prepend|paste|parent|out|openSQLite|open|none|next|newAtEnd|new|move|mouseUp|mouseDown|minimize|min|mid|maximize|max|markTest|markStep|loadTSV|loadCSV|load|ln|listen|leftJustified|left|lastIndexOf|last|kill|keyUp|keyPress|keyDown|join|insertField|insert|info|indexOf|image|ignore|hover|hasField|handler|getRowsAffected|getLength|getField|getError|get|functions|fullscreen|forward|forceType|forceClick|focus|floor|first|findByTitle|find|filter|fastType|exp|exec|error|ensureRValue|endsWith|dismiss|destroy|deleteAll|delete|degreesToRadians|deactivate|daysTo|currentUTC|current|createPath|createDir|create|count|cos|copy|continue|contains|connect|compare|closest|closeToRight|closeToLeft|closeOthers|closeByTitle|closeAll|close|clone|click|clear|child|ceil|break|beginsWith|back|atan|at|asin|applicate|append|all|addYears|addSecs|addMonths|addDescription|addDays|add|activate|acos|accept)\\b', bygroups(Name.Function, Name.Function)),
            (u'\\b(emit|slot)(:\\w+)\\b', bygroups(Keyword, Keyword.Pseudo)),
            (u'\\b(css)(:all|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation), 'main__2'),
            (u'\\b(xpath)(:all|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation, String, Punctuation)),
            (u'\\b(link)(:fragment|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation, String, Punctuation)),
            (u'\\b(links)(:fragment)?(@\\w*)?(\\[)(.*?)(\\])', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation, String, Punctuation)),
            (u'\\b(tag|button|input|field|h[1-6]|legend|span)(:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation, String, Punctuation)),
            (u'\\b(tags)(@\\w*)?(\\[)(.*?)(\\])', bygroups(Name.Function, Name.Variable, Punctuation, String, Punctuation)),
            (u'\\b(web)(\\[\\])', bygroups(Name.Function, Punctuation)),
            (u'\\b(js)(:value)?(@\\w+)?({)', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation), 'main__3'),
            (u'\\b(js)(:file)(\\[)(.*?)(\\])', bygroups(Name.Function, Keyword.Pseudo, Punctuation, String, Punctuation)),
            (u'(\\$\\w+)', bygroups(Name.Function)),
            (u'(@\\w+)', bygroups(Name.Variable)),
            (u'(#\\w+)', bygroups(Name.Variable.Global)),
            (u'(#)', bygroups(Name.Variable)),
            (u'(\\{:)(\\w+)\\b', bygroups(Punctuation, Name)),
            (u'(:)(not|alive|ignore|ajax|\\d+m?s|alt|ever|\\d+times|reverse|max\\d+|min\\d+|all|fragment|try\\d+m?s|try|wait\\d+m?s)\\b', bygroups(Keyword.Pseudo, Keyword.Pseudo)),
            (u'\\b(\\d+\\.?\\d*?)\\b', bygroups(Number)),
            (u'(//.*?//|/:.*?:/|/!.*?\\!/|/\".*?\"/)(\\w*)', bygroups(String.Regex, String.Regex)),
            (u'\\b(sessions|windows|tabs|cookies|alert|tabs|css|xpath|links?|tags?|button|input|field|web|h[1-6]|legend|span)\\b', bygroups(Generic.Error)),
            (u'(\\\")', bygroups(String), 'main__4'),
            (u'(```)', bygroups(Comment), 'main__5'),
            (u'(``)', bygroups(Comment), 'main__6'),
            (u'(`)', bygroups(Comment), 'main__7'),
            (u'(:\\[)', bygroups(Punctuation), 'main__8'),
            (u'(\\[)', bygroups(Operator), 'main__9'),
            (u'(;)', bygroups(Punctuation)),
            (u'(:\\!|::|:\\*|:\\?|&|\\||~|^|%|==|\\!=|>=|<=|<>|<=>|><|>=<|<<|\\!<|<\\*|\\!\\*|\\*\\*|/\'|\\!|>|<|\\+|\\-|\\*|/|\\\\|:|\\(|\\)|\\=|\\,|\\[|\\])', bygroups(Operator)),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ], 
        'jsCode__1' : [
            (u'\\b(abstract|arguments|await|boolean|break|byte|case|catch|char|class|const|continue|debugger|default|delete|do|double|else|enum|eval|export|extends|false|final|finally|float|for|function|goto|if|implements|import|in|instanceof|int|interface|let|long|native|new|null|package|private|protected|public|return|short|static|super|switch|synchronized|this|throw|throws|transient|true|try|typeof|var|void|volatile|while|with|yield)\\b', bygroups(Keyword)),
            (u'(\\${[\\w\\_]+})', bygroups(Name.Function)),
            (u'(\\.[\\w\\_]+)(\\s*\\()', bygroups(Name.Function, Punctuation)),
            (u'(\\.[\\w\\_]+)', bygroups(Name)),
            (u'\\b(window|document|crossfire)\\b', bygroups(Name.Class)),
            (u'({)', bygroups(Punctuation), 'jsCode__1'),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ], 
        'main__1' : [
            (u'\\b(SELECT|FROM|WHERE|LIMIT|INSERT|INTO|VALUE)\\b', bygroups(Keyword)),
            (u'(@?:[\\w\\_]+)', bygroups(Name.Variable)),
            (u'(#:[\\w\\_]+)', bygroups(Name.Variable.Global)),
            (u'([\\w\\_]+)(\\s*\\()', bygroups(Name.Function, Punctuation)),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ], 
        'main__2' : [
            (u'(\\.[\\w\\-\\_]+)', bygroups(Name.Class)),
            (u'(\\#[\\w\\-\\_]+)', bygroups(Name.Variable.Instance)),
            (u'(\\:[\\w\\-\\_]+)(\\s*\\()', bygroups(Name.Function, Punctuation)),
            (u'(\\:[\\w\\-\\_]+)', bygroups(Name)),
            (u'\\b([\\w\\-\\_]+)(=[^\\w\\n\\r]?)([\\w\\-\\_]+)', bygroups(Name, Punctuation, String)),
            (u'\\b(\\d+)\\b', bygroups(Number)),
            (u'\\b([\\w\\-\\_]+)\\b', bygroups(Keyword.Type)),
            (u'(\\[)', bygroups(Punctuation), 'webElement__1'),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ], 
        'main__3' : [
            (u'\\b(abstract|arguments|await|boolean|break|byte|case|catch|char|class|const|continue|debugger|default|delete|do|double|else|enum|eval|export|extends|false|final|finally|float|for|function|goto|if|implements|import|in|instanceof|int|interface|let|long|native|new|null|package|private|protected|public|return|short|static|super|switch|synchronized|this|throw|throws|transient|true|try|typeof|var|void|volatile|while|with|yield)\\b', bygroups(Keyword)),
            (u'(\\${[\\w\\_]+})', bygroups(Name.Function)),
            (u'(\\.[\\w\\_]+)(\\s*\\()', bygroups(Name.Function, Punctuation)),
            (u'(\\.[\\w\\_]+)', bygroups(Name)),
            (u'\\b(window|document|crossfire)\\b', bygroups(Name.Class)),
            (u'({)', bygroups(Punctuation), 'jsCode__1'),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ], 
        'main__4' : [
            (u'(\\\\.)', bygroups(String)),
            (u'(.)', bygroups(String)),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ], 
        'main__5' : [
            ('(\n|\r|\r\n)', String),
            ('.', Comment),
        ], 
        'main__6' : [
            ('(\n|\r|\r\n)', String),
            ('.', Comment),
        ], 
        'main__7' : [
            ('(\n|\r|\r\n)', String),
            ('.', Comment),
        ], 
        'main__8' : [
            (u'\\b(not|alive|ignore|ajax|\\d+m?s|alt|ever|\\d+times|reverse|max\\d+|min\\d+|all|fragment|try\\d+m?s|try|wait\\d+m?s)\\b', bygroups(Keyword.Pseudo)),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ], 
        'main__9' : [
            (u'\\b(now|if|else|for|filter|range|exists|while|do|any|emit|emitter|slot|assert|listen|wait|jammer|switch|case)\\b', bygroups(Keyword)),
            (u'\\b(bool|int|double|string|list|element|set|item|object|void|regex|datetime|session|window|cookie|tab|document|file|query|database|dbmanager|js-file|code-(icl|js|sql)|handler|any|type)\\b', bygroups(Keyword.Type)),
            (u'\\b(icL|Log|Tab|Document|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|State|DB|Query|DBManager|Code|Signal|Datetime)\\b', bygroups(Name.Class)),
            (u'(\\\')(year|y|xPath|x|windows|window|width|visible|value|valid|url|typeName|typeId|tsv|title|texts?|teleport|tagName|tags?|tabs?|sum|sqrt2|source|silentMode|shift|session|selected|secure|second|scriptTimeout|screenshot|right|rects?|readOnly|rValue|quadratic|product|process|previous|pressTime|present|piDiv4|piDiv2|pi|path|partialLinkText|pageLoadTimeout|none|next|name|moveTime|month|minute|min|middle|max|log2e|log10e|ln2|ln10|linkText|link|linear|length|left|last|lValue|implicitTimeout|humanMode|httpOnly|hour|height|format|flashMode|first|expiry|enabled|empty|e|domain|document|day|current|cubic|ctrl|csv|css\\-\\w+|cssSelector|cookies|clickTime|clickable|capacity|bezier|attrs?\\-\\w+|alt|alert|2divSqrtPi|2divPi|1divSqrt2|1divPi)\\b', bygroups(Name, Name)),
            (u'(\\\'props?\\-)(wrap|willValidate|width|volume|videoWidth|videoHeight|valueAsNumber|value|validity|validationMessage|username|useMap|type|title|textLength|textContent|text|target|tagName|tHead|tFoot|tBodies|step|start|srclang|src|spellcheck|span|size|selectionStart|selectionEnd|selectionDirection|selectedOptions|selectedIndex|selected|seeking|search|scrollWidth|scrollTop|scrollLeft|scrollHeight|scope|rowSpan|rowIndex|reversed|required|rel|readyState|readOnly|protocol|previousElementSibling|preload|prefix|poster|position|port|playbackRate|placeholder|paused|pattern|pathname|password|parentElement|outerHTML|origin|options|offsetWidth|offsetTop|offsetParent|offsetLeft|offsetHeight|nodeValue|nodeType|nodeName|noValidate|noModule|nextElementSibling|networkState|naturalWidth|naturalHeight|name|muted|multiple|min|mediaGroup|media|maxLength|max|low|loop|localName|list|length|lastChild|lang|labels|label|kind|isMap|isContentEditable|isConnected|innerText|innerHTML|inert|index|indeterminate|id|httpEquiv|htmlFor|hreflang|href|hostname|host|high|hidden|height|hash|formTarget|formNoValidate|formMethod|formEnctype|formAction|form|firstChild|ended|enctype|encoding|elements|duration|draggable|download|disabled|disableRemotePlayback|dirName|dir|defer|defaultValue|defaultSelected|defaultPlaybackRate|defaultMuted|defaultChecked|default|dateTime|dataset|currentTime|currentSrc|crossOrigin|coords|controls|control|contentEditable|content|computedRole|computedName|complete|cols|colSpan|clientWidth|clientTop|clientLeft|clientHeight|className|cite|childNodes|checked|charset|cells|cellIndex|caption|baseURI|autoplay|autofocus|autocomplete|async|as|areas|alt|allowPaymentRequest|action|accessKeyLabel|accessKey|acceptCharset|accept|abbr)\\b', bygroups(Name, Name)),
            (u'(\\\')([\\w\\-]+)', bygroups(Punctuation, Name)),
            (u'(sql)({)', bygroups(Name.Function, Punctuation), 'main__1'),
            (u'(icl)(:pro)?({)', bygroups(Name.Function, Keyword.Pseudo, Punctuation)),
            (u'(\\.)(write|type|trim|toUpperCase|toUTC|toTimeZone|toPrev|toNext|toLowerCase|toLast|toFirst|tan|sync|switchToParent|switchToFrame|switchToDefault|switchTo|superClick|substring|state|stack|split|sort|sin|setup|setProcess|setAsUserScript|setAsPersistentUserScript|set|sendKeys|seek|secsTo|screenshot|runAsync|run|round|rightJustified|right|return|restoreProcess|restore|resetTime|replaceInStrings|replace|removeOne|removeLast|removeFirst|removeField|removeDuplicates|removeAt|removeAll|remove|refresh|radiansToDegrees|queryTags|queryTag|queryLinks|queryLink|queryByXPath|queryAllByXPath|queryAll|query|process|previous|prev|prepend|paste|parent|out|openSQLite|open|none|next|newAtEnd|new|move|mouseUp|mouseDown|minimize|min|mid|maximize|max|markTest|markStep|loadTSV|loadCSV|load|ln|listen|leftJustified|left|lastIndexOf|last|kill|keyUp|keyPress|keyDown|join|insertField|insert|info|indexOf|image|ignore|hover|hasField|handler|getRowsAffected|getLength|getField|getError|get|functions|fullscreen|forward|forceType|forceClick|focus|floor|first|findByTitle|find|filter|fastType|exp|exec|error|ensureRValue|endsWith|dismiss|destroy|deleteAll|delete|degreesToRadians|deactivate|daysTo|currentUTC|current|createPath|createDir|create|count|cos|copy|continue|contains|connect|compare|closest|closeToRight|closeToLeft|closeOthers|closeByTitle|closeAll|close|clone|click|clear|child|ceil|break|beginsWith|back|atan|at|asin|applicate|append|all|addYears|addSecs|addMonths|addDescription|addDays|add|activate|acos|accept)\\b', bygroups(Name.Function, Name.Function)),
            (u'\\b(emit|slot)(:\\w+)\\b', bygroups(Keyword, Keyword.Pseudo)),
            (u'\\b(css)(:all|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation), 'main__2'),
            (u'\\b(xpath)(:all|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation, String, Punctuation)),
            (u'\\b(link)(:fragment|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation, String, Punctuation)),
            (u'\\b(links)(:fragment)?(@\\w*)?(\\[)(.*?)(\\])', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation, String, Punctuation)),
            (u'\\b(tag|button|input|field|h[1-6]|legend|span)(:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation, String, Punctuation)),
            (u'\\b(tags)(@\\w*)?(\\[)(.*?)(\\])', bygroups(Name.Function, Name.Variable, Punctuation, String, Punctuation)),
            (u'\\b(web)(\\[\\])', bygroups(Name.Function, Punctuation)),
            (u'\\b(js)(:value)?(@\\w+)?({)', bygroups(Name.Function, Keyword.Pseudo, Name.Variable, Punctuation), 'main__3'),
            (u'\\b(js)(:file)(\\[)(.*?)(\\])', bygroups(Name.Function, Keyword.Pseudo, Punctuation, String, Punctuation)),
            (u'(\\$\\w+)', bygroups(Name.Function)),
            (u'(@\\w+)', bygroups(Name.Variable)),
            (u'(#\\w+)', bygroups(Name.Variable.Global)),
            (u'(#)', bygroups(Name.Variable)),
            (u'(\\{:)(\\w+)\\b', bygroups(Punctuation, Name)),
            (u'(:)(not|alive|ignore|ajax|\\d+m?s|alt|ever|\\d+times|reverse|max\\d+|min\\d+|all|fragment|try\\d+m?s|try|wait\\d+m?s)\\b', bygroups(Keyword.Pseudo, Keyword.Pseudo)),
            (u'\\b(\\d+\\.?\\d*?)\\b', bygroups(Number)),
            (u'(//.*?//|/:.*?:/|/!.*?\\!/|/\".*?\"/)(\\w*)', bygroups(String.Regex, String.Regex)),
            (u'\\b(sessions|windows|tabs|cookies|alert|tabs|css|xpath|links?|tags?|button|input|field|web|h[1-6]|legend|span)\\b', bygroups(Generic.Error)),
            (u'(\\\")', bygroups(String), 'main__4'),
            (u'(```)', bygroups(Comment), 'main__5'),
            (u'(``)', bygroups(Comment), 'main__6'),
            (u'(`)', bygroups(Comment), 'main__7'),
            (u'(:\\[)', bygroups(Punctuation), 'main__8'),
            (u'(\\[)', bygroups(Operator), 'main__9'),
            (u'(;)', bygroups(Punctuation)),
            (u'(:\\!|::|:\\*|:\\?|&|\\||~|^|%|==|\\!=|>=|<=|<>|<=>|><|>=<|<<|\\!<|<\\*|\\!\\*|\\*\\*|/\'|\\!|>|<|\\+|\\-|\\*|/|\\\\|:|\\(|\\)|\\=|\\,|\\[|\\])', bygroups(Operator)),
            (u'(\\w+)', bygroups(Name)),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ], 
        'webElement__1' : [
            (u'(\\.[\\w\\-\\_]+)', bygroups(Name.Class)),
            (u'(\\#[\\w\\-\\_]+)', bygroups(Name.Variable.Instance)),
            (u'(\\:[\\w\\-\\_]+)(\\s*\\()', bygroups(Name.Function, Punctuation)),
            (u'(\\:[\\w\\-\\_]+)', bygroups(Name)),
            (u'\\b([\\w\\-\\_]+)(=[^\\w\\n\\r]?)([\\w\\-\\_]+)', bygroups(Name, Punctuation, String)),
            (u'\\b(\\d+)\\b', bygroups(Number)),
            (u'\\b([\\w\\-\\_]+)\\b', bygroups(Keyword.Type)),
            (u'(\\[)', bygroups(Punctuation), 'webElement__1'),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ]
    }

