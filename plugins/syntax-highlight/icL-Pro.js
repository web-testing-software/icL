/*
* To try in Ace editor, copy and paste into the mode creator
* here : http://ace.c9.io/tool/mode_creator.html
*/

define(function(require, exports, module) {
"use strict";
var oop = require("../lib/oop");
var TextHighlightRules = require("./text_highlight_rules").TextHighlightRules;
/* --------------------- START ----------------------------- */
var IclProHighlightRules = function() {
this.$rules = {
"start" : [
   {
      "token" : "keyword.control",
      "regex" : "\\b(now|if|else|for|filter|range|exists|while|do|any|emit|emitter|slot|assert|listen|wait|jammer|switch|case)\\b"
   },
   {
      "token" : "meta.type",
      "regex" : "\\b(bool|int|double|string|list|element|set|item|object|void|regex|datetime|session|window|cookie|tab|document|file|query|database|dbmanager|js-file|code-(icl|js|sql)|handler|any|type)\\b"
   },
   {
      "token" : "meta.class",
      "regex" : "\\b(icL|Log|Tab|Document|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|State|DB|Query|DBManager|Code|Signal|Datetime)\\b"
   },
   {
      "token" : ["variable.other.member", "variable.other.member"],
      "regex" : "(\\')(year|y|xPath|x|windows|window|width|visible|value|valid|url|typeName|typeId|tsv|title|texts?|teleport|tagName|tags?|tabs?|sum|sqrt2|source|silentMode|shift|session|selected|secure|second|scriptTimeout|screenshot|right|rects?|readOnly|rValue|quadratic|product|process|previous|pressTime|present|piDiv4|piDiv2|pi|path|partialLinkText|pageLoadTimeout|none|next|name|moveTime|month|minute|min|middle|max|log2e|log10e|ln2|ln10|linkText|link|linear|length|left|last|lValue|implicitTimeout|humanMode|httpOnly|hour|height|format|flashMode|first|expiry|enabled|empty|e|domain|document|day|current|cubic|ctrl|csv|css\\-\\w+|cssSelector|cookies|clickTime|clickable|capacity|bezier|attrs?\\-\\w+|alt|alert|2divSqrtPi|2divPi|1divSqrt2|1divPi)\\b"
   },
   {
      "token" : ["variable.other.member", "variable.other.member"],
      "regex" : "(\\'props?\\-)(wrap|willValidate|width|volume|videoWidth|videoHeight|valueAsNumber|value|validity|validationMessage|username|useMap|type|title|textLength|textContent|text|target|tagName|tHead|tFoot|tBodies|step|start|srclang|src|spellcheck|span|size|selectionStart|selectionEnd|selectionDirection|selectedOptions|selectedIndex|selected|seeking|search|scrollWidth|scrollTop|scrollLeft|scrollHeight|scope|rowSpan|rowIndex|reversed|required|rel|readyState|readOnly|protocol|previousElementSibling|preload|prefix|poster|position|port|playbackRate|placeholder|paused|pattern|pathname|password|parentElement|outerHTML|origin|options|offsetWidth|offsetTop|offsetParent|offsetLeft|offsetHeight|nodeValue|nodeType|nodeName|noValidate|noModule|nextElementSibling|networkState|naturalWidth|naturalHeight|name|muted|multiple|min|mediaGroup|media|maxLength|max|low|loop|localName|list|length|lastChild|lang|labels|label|kind|isMap|isContentEditable|isConnected|innerText|innerHTML|inert|index|indeterminate|id|httpEquiv|htmlFor|hreflang|href|hostname|host|high|hidden|height|hash|formTarget|formNoValidate|formMethod|formEnctype|formAction|form|firstChild|ended|enctype|encoding|elements|duration|draggable|download|disabled|disableRemotePlayback|dirName|dir|defer|defaultValue|defaultSelected|defaultPlaybackRate|defaultMuted|defaultChecked|default|dateTime|dataset|currentTime|currentSrc|crossOrigin|coords|controls|control|contentEditable|content|computedRole|computedName|complete|cols|colSpan|clientWidth|clientTop|clientLeft|clientHeight|className|cite|childNodes|checked|charset|cells|cellIndex|caption|baseURI|autoplay|autofocus|autocomplete|async|as|areas|alt|allowPaymentRequest|action|accessKeyLabel|accessKey|acceptCharset|accept|abbr)\\b"
   },
   {
      "token" : ["punctuation", "variable.other.member"],
      "regex" : "(\\')([\\w\\-]+)"
   },
   {
      "token" : ["entity.name.function", "punctuation"],
      "regex" : "(sql)({)",
      "push" : "main__1"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "punctuation"],
      "regex" : "(icl)(:pro)?({)"
   },
   {
      "token" : ["entity.name.function", "entity.name.function"],
      "regex" : "(\\.)(write|type|trim|toUpperCase|toUTC|toTimeZone|toPrev|toNext|toLowerCase|toLast|toFirst|tan|sync|switchToParent|switchToFrame|switchToDefault|switchTo|superClick|substring|state|stack|split|sort|sin|setup|setProcess|setAsUserScript|setAsPersistentUserScript|set|sendKeys|seek|secsTo|screenshot|runAsync|run|round|rightJustified|right|return|restoreProcess|restore|resetTime|replaceInStrings|replace|removeOne|removeLast|removeFirst|removeField|removeDuplicates|removeAt|removeAll|remove|refresh|radiansToDegrees|queryTags|queryTag|queryLinks|queryLink|queryByXPath|queryAllByXPath|queryAll|query|process|previous|prev|prepend|paste|parent|out|openSQLite|open|none|next|newAtEnd|new|move|mouseUp|mouseDown|minimize|min|mid|maximize|max|markTest|markStep|loadTSV|loadCSV|load|ln|listen|leftJustified|left|lastIndexOf|last|kill|keyUp|keyPress|keyDown|join|insertField|insert|info|indexOf|image|ignore|hover|hasField|handler|getRowsAffected|getLength|getField|getError|get|functions|fullscreen|forward|forceType|forceClick|focus|floor|first|findByTitle|find|filter|fastType|exp|exec|error|ensureRValue|endsWith|dismiss|destroy|deleteAll|delete|degreesToRadians|deactivate|daysTo|currentUTC|current|createPath|createDir|create|count|cos|copy|continue|contains|connect|compare|closest|closeToRight|closeToLeft|closeOthers|closeByTitle|closeAll|close|clone|click|clear|child|ceil|break|beginsWith|back|atan|at|asin|applicate|append|all|addYears|addSecs|addMonths|addDescription|addDays|add|activate|acos|accept)\\b"
   },
   {
      "token" : ["keyword.control", "entity.name.tag"],
      "regex" : "\\b(emit|slot)(:\\w+)\\b"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation"],
      "regex" : "\\b(css)(:all|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)",
      "push" : "main__2"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(xpath)(:all|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(link)(:fragment|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(links)(:fragment)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(tag|button|input|field|h[1-6]|legend|span)(:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(tags)(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "punctuation"],
      "regex" : "\\b(web)(\\[\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation"],
      "regex" : "\\b(js)(:value)?(@\\w+)?({)",
      "push" : "main__3"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(js)(:file)(\\[)(.*?)(\\])"
   },
   {
      "token" : "entity.name.function",
      "regex" : "(\\$\\w+)"
   },
   {
      "token" : "variable.other",
      "regex" : "(@\\w+)"
   },
   {
      "token" : "variable.language",
      "regex" : "(#\\w+)"
   },
   {
      "token" : "variable.other",
      "regex" : "(#)"
   },
   {
      "token" : ["punctuation", "variable.other.member"],
      "regex" : "(\\{:)(\\w+)\\b"
   },
   {
      "token" : ["entity.name.tag", "entity.name.tag"],
      "regex" : "(:)(not|alive|ignore|ajax|\\d+m?s|alt|ever|\\d+times|reverse|max\\d+|min\\d+|all|fragment|try\\d+m?s|try|wait\\d+m?s)\\b"
   },
   {
      "token" : "constant.numeric",
      "regex" : "\\b(\\d+\\.?\\d*?)\\b"
   },
   {
      "token" : ["string.regexp", "string.regexp"],
      "regex" : "(//.*?//|/:.*?:/|/!.*?\\!/|/\".*?\"/)(\\w*)"
   },
   {
      "token" : "invalid",
      "regex" : "\\b(sessions|windows|tabs|cookies|alert|tabs|css|xpath|links?|tags?|button|input|field|web|h[1-6]|legend|span)\\b"
   },
   {
      "token" : "string.quoted.single",
      "regex" : "(\\\")",
      "push" : "main__4"
   },
   {
      "token" : "comment",
      "regex" : "(```)",
      "push" : "main__5"
   },
   {
      "token" : "comment",
      "regex" : "(``)",
      "push" : "main__6"
   },
   {
      "token" : "comment",
      "regex" : "(`)",
      "push" : "main__7"
   },
   {
      "token" : "punctuation",
      "regex" : "(:\\[)",
      "push" : "main__8"
   },
   {
      "token" : "keyword.operator",
      "regex" : "(\\[)",
      "push" : "main__9"
   },
   {
      "token" : "punctuation",
      "regex" : "(;)"
   },
   {
      "token" : "keyword.operator",
      "regex" : "(:\\!|::|:\\*|:\\?|&|\\||~|^|%|==|\\!=|>=|<=|<>|<=>|><|>=<|<<|\\!<|<\\*|\\!\\*|\\*\\*|/'|\\!|>|<|\\+|\\-|\\*|/|\\\\|:|\\(|\\)|\\=|\\,|\\[|\\])"
   },
   {
      defaultToken : "text",
   }
], 
"jsCode__1" : [
   {
      "token" : "punctuation",
      "regex" : "(})",
      "next" : "pop"
   },
   {
      "token" : "keyword.control",
      "regex" : "\\b(abstract|arguments|await|boolean|break|byte|case|catch|char|class|const|continue|debugger|default|delete|do|double|else|enum|eval|export|extends|false|final|finally|float|for|function|goto|if|implements|import|in|instanceof|int|interface|let|long|native|new|null|package|private|protected|public|return|short|static|super|switch|synchronized|this|throw|throws|transient|true|try|typeof|var|void|volatile|while|with|yield)\\b"
   },
   {
      "token" : "entity.name.function",
      "regex" : "(\\${[\\w\\_]+})"
   },
   {
      "token" : ["entity.name.function", "punctuation"],
      "regex" : "(\\.[\\w\\_]+)(\\s*\\()"
   },
   {
      "token" : "variable.other.member",
      "regex" : "(\\.[\\w\\_]+)"
   },
   {
      "token" : "meta.class",
      "regex" : "\\b(window|document|crossfire)\\b"
   },
   {
      "token" : "punctuation",
      "regex" : "({)",
      "push" : "jsCode__1"
   },
   {
      defaultToken : "text",
   }
], 
"main__1" : [
   {
      "token" : "punctuation",
      "regex" : "(})",
      "next" : "pop"
   },
   {
      "token" : "keyword.control",
      "regex" : "\\b(SELECT|FROM|WHERE|LIMIT|INSERT|INTO|VALUE)\\b"
   },
   {
      "token" : "variable.other",
      "regex" : "(@?:[\\w\\_]+)"
   },
   {
      "token" : "variable.language",
      "regex" : "(#:[\\w\\_]+)"
   },
   {
      "token" : ["entity.name.function", "punctuation"],
      "regex" : "([\\w\\_]+)(\\s*\\()"
   },
   {
      defaultToken : "text",
   }
], 
"main__2" : [
   {
      "token" : "punctuation",
      "regex" : "(\\])",
      "next" : "pop"
   },
   {
      "token" : "meta.class",
      "regex" : "(\\.[\\w\\-\\_]+)"
   },
   {
      "token" : "entity.name.struct",
      "regex" : "(\\#[\\w\\-\\_]+)"
   },
   {
      "token" : ["entity.name.function", "punctuation"],
      "regex" : "(\\:[\\w\\-\\_]+)(\\s*\\()"
   },
   {
      "token" : "entity.name.enum",
      "regex" : "(\\:[\\w\\-\\_]+)"
   },
   {
      "token" : ["variable.other.member", "punctuation", "string.quoted.single"],
      "regex" : "\\b([\\w\\-\\_]+)(=[^\\w]?)([\\w\\-\\_]+)"
   },
   {
      "token" : "constant.numeric",
      "regex" : "\\b(\\d+)\\b"
   },
   {
      "token" : "entity.name.type",
      "regex" : "\\b([\\w\\-\\_]+)\\b"
   },
   {
      "token" : "punctuation",
      "regex" : "(\\[)",
      "push" : "webElement__1"
   },
   {
      defaultToken : "text",
   }
], 
"main__3" : [
   {
      "token" : "punctuation",
      "regex" : "(})",
      "next" : "pop"
   },
   {
      "token" : "keyword.control",
      "regex" : "\\b(abstract|arguments|await|boolean|break|byte|case|catch|char|class|const|continue|debugger|default|delete|do|double|else|enum|eval|export|extends|false|final|finally|float|for|function|goto|if|implements|import|in|instanceof|int|interface|let|long|native|new|null|package|private|protected|public|return|short|static|super|switch|synchronized|this|throw|throws|transient|true|try|typeof|var|void|volatile|while|with|yield)\\b"
   },
   {
      "token" : "entity.name.function",
      "regex" : "(\\${[\\w\\_]+})"
   },
   {
      "token" : ["entity.name.function", "punctuation"],
      "regex" : "(\\.[\\w\\_]+)(\\s*\\()"
   },
   {
      "token" : "variable.other.member",
      "regex" : "(\\.[\\w\\_]+)"
   },
   {
      "token" : "meta.class",
      "regex" : "\\b(window|document|crossfire)\\b"
   },
   {
      "token" : "punctuation",
      "regex" : "({)",
      "push" : "jsCode__1"
   },
   {
      defaultToken : "text",
   }
], 
"main__4" : [
   {
      "token" : "string.quoted.single",
      "regex" : "(\\\")",
      "next" : "pop"
   },
   {
      "token" : "string.quoted.single",
      "regex" : "(\\\\.)"
   },
   {
      "token" : "string.quoted.single",
      "regex" : "(.)"
   },
   {
      defaultToken : "text",
   }
], 
"main__5" : [
   {
      "token" : "comment",
      "regex" : "(```)",
      "next" : "pop"
   },
   {
      defaultToken : "comment",
   }
], 
"main__6" : [
   {
      "token" : "comment",
      "regex" : "($)",
      "next" : "pop"
   },
   {
      defaultToken : "comment",
   }
], 
"main__7" : [
   {
      "token" : "comment",
      "regex" : "(`)",
      "next" : "pop"
   },
   {
      defaultToken : "comment",
   }
], 
"main__8" : [
   {
      "token" : "punctuation",
      "regex" : "(\\])",
      "next" : "pop"
   },
   {
      "token" : "entity.name.tag",
      "regex" : "\\b(not|alive|ignore|ajax|\\d+m?s|alt|ever|\\d+times|reverse|max\\d+|min\\d+|all|fragment|try\\d+m?s|try|wait\\d+m?s)\\b"
   },
   {
      defaultToken : "text",
   }
], 
"main__9" : [
   {
      "token" : "keyword.operator",
      "regex" : "(\\])",
      "next" : "pop"
   },
   {
      "token" : "keyword.control",
      "regex" : "\\b(now|if|else|for|filter|range|exists|while|do|any|emit|emitter|slot|assert|listen|wait|jammer|switch|case)\\b"
   },
   {
      "token" : "meta.type",
      "regex" : "\\b(bool|int|double|string|list|element|set|item|object|void|regex|datetime|session|window|cookie|tab|document|file|query|database|dbmanager|js-file|code-(icl|js|sql)|handler|any|type)\\b"
   },
   {
      "token" : "meta.class",
      "regex" : "\\b(icL|Log|Tab|Document|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|State|DB|Query|DBManager|Code|Signal|Datetime)\\b"
   },
   {
      "token" : ["variable.other.member", "variable.other.member"],
      "regex" : "(\\')(year|y|xPath|x|windows|window|width|visible|value|valid|url|typeName|typeId|tsv|title|texts?|teleport|tagName|tags?|tabs?|sum|sqrt2|source|silentMode|shift|session|selected|secure|second|scriptTimeout|screenshot|right|rects?|readOnly|rValue|quadratic|product|process|previous|pressTime|present|piDiv4|piDiv2|pi|path|partialLinkText|pageLoadTimeout|none|next|name|moveTime|month|minute|min|middle|max|log2e|log10e|ln2|ln10|linkText|link|linear|length|left|last|lValue|implicitTimeout|humanMode|httpOnly|hour|height|format|flashMode|first|expiry|enabled|empty|e|domain|document|day|current|cubic|ctrl|csv|css\\-\\w+|cssSelector|cookies|clickTime|clickable|capacity|bezier|attrs?\\-\\w+|alt|alert|2divSqrtPi|2divPi|1divSqrt2|1divPi)\\b"
   },
   {
      "token" : ["variable.other.member", "variable.other.member"],
      "regex" : "(\\'props?\\-)(wrap|willValidate|width|volume|videoWidth|videoHeight|valueAsNumber|value|validity|validationMessage|username|useMap|type|title|textLength|textContent|text|target|tagName|tHead|tFoot|tBodies|step|start|srclang|src|spellcheck|span|size|selectionStart|selectionEnd|selectionDirection|selectedOptions|selectedIndex|selected|seeking|search|scrollWidth|scrollTop|scrollLeft|scrollHeight|scope|rowSpan|rowIndex|reversed|required|rel|readyState|readOnly|protocol|previousElementSibling|preload|prefix|poster|position|port|playbackRate|placeholder|paused|pattern|pathname|password|parentElement|outerHTML|origin|options|offsetWidth|offsetTop|offsetParent|offsetLeft|offsetHeight|nodeValue|nodeType|nodeName|noValidate|noModule|nextElementSibling|networkState|naturalWidth|naturalHeight|name|muted|multiple|min|mediaGroup|media|maxLength|max|low|loop|localName|list|length|lastChild|lang|labels|label|kind|isMap|isContentEditable|isConnected|innerText|innerHTML|inert|index|indeterminate|id|httpEquiv|htmlFor|hreflang|href|hostname|host|high|hidden|height|hash|formTarget|formNoValidate|formMethod|formEnctype|formAction|form|firstChild|ended|enctype|encoding|elements|duration|draggable|download|disabled|disableRemotePlayback|dirName|dir|defer|defaultValue|defaultSelected|defaultPlaybackRate|defaultMuted|defaultChecked|default|dateTime|dataset|currentTime|currentSrc|crossOrigin|coords|controls|control|contentEditable|content|computedRole|computedName|complete|cols|colSpan|clientWidth|clientTop|clientLeft|clientHeight|className|cite|childNodes|checked|charset|cells|cellIndex|caption|baseURI|autoplay|autofocus|autocomplete|async|as|areas|alt|allowPaymentRequest|action|accessKeyLabel|accessKey|acceptCharset|accept|abbr)\\b"
   },
   {
      "token" : ["punctuation", "variable.other.member"],
      "regex" : "(\\')([\\w\\-]+)"
   },
   {
      "token" : ["entity.name.function", "punctuation"],
      "regex" : "(sql)({)",
      "push" : "main__1"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "punctuation"],
      "regex" : "(icl)(:pro)?({)"
   },
   {
      "token" : ["entity.name.function", "entity.name.function"],
      "regex" : "(\\.)(write|type|trim|toUpperCase|toUTC|toTimeZone|toPrev|toNext|toLowerCase|toLast|toFirst|tan|sync|switchToParent|switchToFrame|switchToDefault|switchTo|superClick|substring|state|stack|split|sort|sin|setup|setProcess|setAsUserScript|setAsPersistentUserScript|set|sendKeys|seek|secsTo|screenshot|runAsync|run|round|rightJustified|right|return|restoreProcess|restore|resetTime|replaceInStrings|replace|removeOne|removeLast|removeFirst|removeField|removeDuplicates|removeAt|removeAll|remove|refresh|radiansToDegrees|queryTags|queryTag|queryLinks|queryLink|queryByXPath|queryAllByXPath|queryAll|query|process|previous|prev|prepend|paste|parent|out|openSQLite|open|none|next|newAtEnd|new|move|mouseUp|mouseDown|minimize|min|mid|maximize|max|markTest|markStep|loadTSV|loadCSV|load|ln|listen|leftJustified|left|lastIndexOf|last|kill|keyUp|keyPress|keyDown|join|insertField|insert|info|indexOf|image|ignore|hover|hasField|handler|getRowsAffected|getLength|getField|getError|get|functions|fullscreen|forward|forceType|forceClick|focus|floor|first|findByTitle|find|filter|fastType|exp|exec|error|ensureRValue|endsWith|dismiss|destroy|deleteAll|delete|degreesToRadians|deactivate|daysTo|currentUTC|current|createPath|createDir|create|count|cos|copy|continue|contains|connect|compare|closest|closeToRight|closeToLeft|closeOthers|closeByTitle|closeAll|close|clone|click|clear|child|ceil|break|beginsWith|back|atan|at|asin|applicate|append|all|addYears|addSecs|addMonths|addDescription|addDays|add|activate|acos|accept)\\b"
   },
   {
      "token" : ["keyword.control", "entity.name.tag"],
      "regex" : "\\b(emit|slot)(:\\w+)\\b"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation"],
      "regex" : "\\b(css)(:all|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)",
      "push" : "main__2"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(xpath)(:all|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(link)(:fragment|:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(links)(:fragment)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(tag|button|input|field|h[1-6]|legend|span)(:try\\d+m?s|:try|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(tags)(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "punctuation"],
      "regex" : "\\b(web)(\\[\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation"],
      "regex" : "\\b(js)(:value)?(@\\w+)?({)",
      "push" : "main__3"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(js)(:file)(\\[)(.*?)(\\])"
   },
   {
      "token" : "entity.name.function",
      "regex" : "(\\$\\w+)"
   },
   {
      "token" : "variable.other",
      "regex" : "(@\\w+)"
   },
   {
      "token" : "variable.language",
      "regex" : "(#\\w+)"
   },
   {
      "token" : "variable.other",
      "regex" : "(#)"
   },
   {
      "token" : ["punctuation", "variable.other.member"],
      "regex" : "(\\{:)(\\w+)\\b"
   },
   {
      "token" : ["entity.name.tag", "entity.name.tag"],
      "regex" : "(:)(not|alive|ignore|ajax|\\d+m?s|alt|ever|\\d+times|reverse|max\\d+|min\\d+|all|fragment|try\\d+m?s|try|wait\\d+m?s)\\b"
   },
   {
      "token" : "constant.numeric",
      "regex" : "\\b(\\d+\\.?\\d*?)\\b"
   },
   {
      "token" : ["string.regexp", "string.regexp"],
      "regex" : "(//.*?//|/:.*?:/|/!.*?\\!/|/\".*?\"/)(\\w*)"
   },
   {
      "token" : "invalid",
      "regex" : "\\b(sessions|windows|tabs|cookies|alert|tabs|css|xpath|links?|tags?|button|input|field|web|h[1-6]|legend|span)\\b"
   },
   {
      "token" : "string.quoted.single",
      "regex" : "(\\\")",
      "push" : "main__4"
   },
   {
      "token" : "comment",
      "regex" : "(```)",
      "push" : "main__5"
   },
   {
      "token" : "comment",
      "regex" : "(``)",
      "push" : "main__6"
   },
   {
      "token" : "comment",
      "regex" : "(`)",
      "push" : "main__7"
   },
   {
      "token" : "punctuation",
      "regex" : "(:\\[)",
      "push" : "main__8"
   },
   {
      "token" : "keyword.operator",
      "regex" : "(\\[)",
      "push" : "main__9"
   },
   {
      "token" : "punctuation",
      "regex" : "(;)"
   },
   {
      "token" : "keyword.operator",
      "regex" : "(:\\!|::|:\\*|:\\?|&|\\||~|^|%|==|\\!=|>=|<=|<>|<=>|><|>=<|<<|\\!<|<\\*|\\!\\*|\\*\\*|/'|\\!|>|<|\\+|\\-|\\*|/|\\\\|:|\\(|\\)|\\=|\\,|\\[|\\])"
   },
   {
      "token" : "variable.other.member",
      "regex" : "(\\w+)"
   },
   {
      defaultToken : "text",
   }
], 
"webElement__1" : [
   {
      "token" : "punctuation",
      "regex" : "(\\])",
      "next" : "pop"
   },
   {
      "token" : "meta.class",
      "regex" : "(\\.[\\w\\-\\_]+)"
   },
   {
      "token" : "entity.name.struct",
      "regex" : "(\\#[\\w\\-\\_]+)"
   },
   {
      "token" : ["entity.name.function", "punctuation"],
      "regex" : "(\\:[\\w\\-\\_]+)(\\s*\\()"
   },
   {
      "token" : "entity.name.enum",
      "regex" : "(\\:[\\w\\-\\_]+)"
   },
   {
      "token" : ["variable.other.member", "punctuation", "string.quoted.single"],
      "regex" : "\\b([\\w\\-\\_]+)(=[^\\w]?)([\\w\\-\\_]+)"
   },
   {
      "token" : "constant.numeric",
      "regex" : "\\b(\\d+)\\b"
   },
   {
      "token" : "entity.name.type",
      "regex" : "\\b([\\w\\-\\_]+)\\b"
   },
   {
      "token" : "punctuation",
      "regex" : "(\\[)",
      "push" : "webElement__1"
   },
   {
      defaultToken : "text",
   }
]
};
this.normalizeRules();
};
/* ------------------------ END ------------------------------ */
oop.inherits(IclProHighlightRules, TextHighlightRules);
exports.IclProHighlightRules = IclProHighlightRules;
});
