# -*- coding: utf-8 -*- #

module Rouge
  module Lexers
    class IclPro < RegexLexer
      title     "icL_Pro"
      tag       'IclPro'
      mimetypes 'text/x-icL_Pro'
      filenames '*.icL', '*.icLPro'

      state:root do
          rule /\b(now|if|else|for|filter|range|exists|while|do|any|emit|emitter|slot|assert|listen|wait|jammer|switch|case)\b/, Keyword
          rule /\b(bool|int|double|string|list|element|set|item|object|void|regex|datetime|session|window|cookie|tab|document|file|query|database|dbmanager|js-file|code-(icl|js|sql)|handle|any|type)\b/, Keyword::Type
          rule /\b(icL|Log|Tab|Document|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|State|DB|Query|DBManager|Code|Signal|Datetime)\b/, Name::Class
          rule /(\')(year|y|xPath|x|windows|window|width|visible|value|valid|url|typeName|typeId|tsv|title|texts?|teleport|tagName|tags?|tabs?|sum|sqrt2|source|silentMode|shift|session|selected|secure|second|scriptTimeout|screenshot|right|rects?|readOnly|rValue|quadratic|product|process|previous|pressTime|present|piDiv4|piDiv2|pi|path|partialLinkText|pageLoadTimeout|none|next|name|moveTime|month|minute|min|middle|max|log2e|log10e|ln2|ln10|linkText|link|linear|length|left|last|lValue|implicitTimeout|humanMode|httpOnly|hour|height|format|flashMode|first|expiry|enabled|empty|e|domain|document|day|current|cubic|ctrl|csv|css\-\w+|cssSelector|cookies|clickTime|clickable|capacity|bezier|attrs?\-\w+|alt|alert|2divSqrtPi|2divPi|1divSqrt2|1divPi)\b/ do
            groups Name, Name
          end
          rule /(\'props?\-)(wrap|willValidate|width|volume|videoWidth|videoHeight|valueAsNumber|value|validity|validationMessage|username|useMap|type|title|textLength|textContent|text|target|tagName|tHead|tFoot|tBodies|step|start|srclang|src|spellcheck|span|size|selectionStart|selectionEnd|selectionDirection|selectedOptions|selectedIndex|selected|seeking|search|scrollWidth|scrollTop|scrollLeft|scrollHeight|scope|rowSpan|rowIndex|reversed|required|rel|readyState|readOnly|protocol|previousElementSibling|preload|prefix|poster|position|port|playbackRate|placeholder|paused|pattern|pathname|password|parentElement|outerHTML|origin|options|offsetWidth|offsetTop|offsetParent|offsetLeft|offsetHeight|nodeValue|nodeType|nodeName|noValidate|noModule|nextElementSibling|networkState|naturalWidth|naturalHeight|name|muted|multiple|min|mediaGroup|media|maxLength|max|low|loop|localName|list|length|lastChild|lang|labels|label|kind|isMap|isContentEditable|isConnected|innerText|innerHTML|inert|index|indeterminate|id|httpEquiv|htmlFor|hreflang|href|hostname|host|high|hidden|height|hash|formTarget|formNoValidate|formMethod|formEnctype|formAction|form|firstChild|ended|enctype|encoding|elements|duration|draggable|download|disabled|disableRemotePlayback|dirName|dir|defer|defaultValue|defaultSelected|defaultPlaybackRate|defaultMuted|defaultChecked|default|dateTime|dataset|currentTime|currentSrc|crossOrigin|coords|controls|control|contentEditable|content|computedRole|computedName|complete|cols|colSpan|clientWidth|clientTop|clientLeft|clientHeight|className|cite|childNodes|checked|charset|cells|cellIndex|caption|baseURI|autoplay|autofocus|autocomplete|async|as|areas|alt|allowPaymentRequest|action|accessKeyLabel|accessKey|acceptCharset|accept|abbr)\b/ do
            groups Name, Name
          end
          rule /(\')([\w\-]+)/ do
            groups Punctuation, Name
          end
          rule /(sql)({)/ do
            groups Name::Function, Punctuation
            push :main__1
          end
          rule /(icl)(:pro)?({)/ do
            groups Name::Function, Keyword::Pseudo, Punctuation
          end
          rule /(\.)(write|type|trim|toUpperCase|toUTC|toTimeZone|toPrev|toNext|toLowerCase|toLast|toFirst|tan|sync|switchToParent|switchToFrame|switchToDefault|switchTo|superClick|substring|state|stack|split|sort|sin|setup|setProcess|setAsUserScript|setAsPersistentUserScript|set|sendKeys|seek|secsTo|screenshot|save|runAsync|run|round|rightJustified|right|return|restoreProcess|restore|resetTime|replaceInStrings|replace|removeOne|removeLast|removeFirst|removeField|removeDuplicates|removeAt|removeAll|remove|refresh|radiansToDegrees|queryTags|queryTag|queryLinks|queryLink|queryByXPath|queryAllByXPath|queryAll|query|process|previous|prev|prepend|paste|parent|out|openSQLite|open|none|next|newAtEnd|new|move|mouseUp|mouseDown|minimize|min|mid|maximize|max|markTest|markStep|loadTSV|loadCSV|load|ln|listen|leftJustified|left|lastIndexOf|last|kill|keyUp|keyPress|keyDown|join|insertField|insert|info|indexOf|image|ignore|hover|hasField|handle|getRowsAffected|getLength|getField|getError|get|functions|fullscreen|forward|forceType|forceClick|focus|floor|first|findByTitle|find|filter|fastType|exp|exec|error|ensureRValue|endsWith|dismiss|destroy|deleteAll|delete|degreesToRadians|deactivate|daysTo|currentUTC|current|createPath|createDir|create|count|cos|copy|continue|contains|connect|compare|closest|closeToRight|closeToLeft|closeOthers|closeByTitle|closeAll|close|clone|click|clear|child|ceil|break|beginsWith|back|atan|at|asin|applicate|append|all|addYears|addSecs|addMonths|addDescription|addDays|add|activate|acos|accept)\b/ do
            groups Name::Function, Name::Function
          end
          rule /\b(emit|slot)(:\w+)\b/ do
            groups Keyword, Keyword::Pseudo
          end
          rule /\b(css)(:all|:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation
            push :main__2
          end
          rule /\b(xpath)(:all|:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(link)(:fragment|:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(links)(:fragment)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(tag|button|input|field|h[1-6]|legend|span)(:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(tags)(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(web)(\[\])/ do
            groups Name::Function, Punctuation
          end
          rule /\b(js)(:value)?(@\w*)?({)/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation
            push :main__3
          end
          rule /\b(js)(:file)(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Punctuation, String, Punctuation
          end
          rule /(\$\w+)/, Name::Function
          rule /(@\w*)/, Name::Variable
          rule /(#\w+)/, Name::Variable::Global
          rule /(#)/, Name::Variable
          rule /(\{:)(\w+)\b/ do
            groups Punctuation, Name
          end
          rule /(:)(not|alive|ignore|ajax|\d+m?s|alt|ever|\d+times|reverse|max\d+|min\d+|all|fragment|try\d+m?s|try|wait\d+m?s)\b/ do
            groups Keyword::Pseudo, Keyword::Pseudo
          end
          rule /\b(\d+\.?\d*?)\b/, Number
          rule /(\/\/.*?\/\/|\/:.*?:\/|\/!.*?\!\/|\/".*?"\/)(\w*)/ do
            groups String::Regex, String::Regex
          end
          rule /\b(sessions|windows|tabs|cookies|alert|tabs|css|xpath|links?|tags?|button|input|field|web|h[1-6]|legend|span)\b/, Generic::Error
          rule /(\")/, String, :main__4
          rule /(```)/, Comment, :main__5
          rule /(``)/, Comment, :main__6
          rule /(`)/, Comment, :main__7
          rule /(:\[)/, Punctuation, :main__8
          rule /(\[)/, Operator, :main__9
          rule /(;)/, Punctuation
          rule /(:\!|::|:\*|:\?|&|\||~|^|%|==|\!=|>=|<=|<>|<=>|><|>=<|<<|\!<|<\*|\!\*|\*\*|\/'|\!|>|<|\+|\-|\*|\/|\\|:|\(|\)|\=|\,|\[|\])/, Operator
          rule /(\n|\r|\r\n)/, String
          rule /./, String
      end

      state:jsCode__1 do
          rule /\b(abstract|arguments|await|boolean|break|byte|case|catch|char|class|const|continue|debugger|default|delete|do|double|else|enum|eval|export|extends|false|final|finally|float|for|function|goto|if|implements|import|in|instanceof|int|interface|let|long|native|new|null|package|private|protected|public|return|short|static|super|switch|synchronized|this|throw|throws|transient|true|try|typeof|var|void|volatile|while|with|yield)\b/, Keyword
          rule /(\${[\w\_]+})/, Name::Function
          rule /(\.[\w\_]+)(\s*\()/ do
            groups Name::Function, Punctuation
          end
          rule /(\.[\w\_]+)/, Name
          rule /\b(window|document|crossfire)\b/, Name::Class
          rule /({)/, Punctuation, :jsCode__1
          rule /(\n|\r|\r\n)/, String
          rule /./, String
      end

      state:main__1 do
          rule /\b(SELECT|FROM|WHERE|LIMIT|INSERT|INTO|VALUE)\b/, Keyword
          rule /(@?:[\w\_]+)/, Name::Variable
          rule /(#:[\w\_]+)/, Name::Variable::Global
          rule /([\w\_]+)(\s*\()/ do
            groups Name::Function, Punctuation
          end
          rule /(\n|\r|\r\n)/, String
          rule /./, String
      end

      state:main__2 do
          rule /(\.[\w\-\_]+)/, Name::Class
          rule /(\#[\w\-\_]+)/, Name::Variable::Instance
          rule /(\:[\w\-\_]+)(\s*\()/ do
            groups Name::Function, Punctuation
          end
          rule /(\:[\w\-\_]+)/, Name
          rule /\b([\w\-\_]+)(=[^\w\n\r]?)([\w\-\_]+)/ do
            groups Name, Punctuation, String
          end
          rule /\b(\d+)\b/, Number
          rule /\b([\w\-\_]+)\b/, Keyword::Type
          rule /(\[)/, Punctuation, :webElement__1
          rule /(\n|\r|\r\n)/, String
          rule /./, String
      end

      state:main__3 do
          rule /\b(abstract|arguments|await|boolean|break|byte|case|catch|char|class|const|continue|debugger|default|delete|do|double|else|enum|eval|export|extends|false|final|finally|float|for|function|goto|if|implements|import|in|instanceof|int|interface|let|long|native|new|null|package|private|protected|public|return|short|static|super|switch|synchronized|this|throw|throws|transient|true|try|typeof|var|void|volatile|while|with|yield)\b/, Keyword
          rule /(\${[\w\_]+})/, Name::Function
          rule /(\.[\w\_]+)(\s*\()/ do
            groups Name::Function, Punctuation
          end
          rule /(\.[\w\_]+)/, Name
          rule /\b(window|document|crossfire)\b/, Name::Class
          rule /({)/, Punctuation, :jsCode__1
          rule /(\n|\r|\r\n)/, String
          rule /./, String
      end

      state:main__4 do
          rule /(\\.)/, String
          rule /(.)/, String
          rule /(\n|\r|\r\n)/, String
          rule /./, String
      end

      state:main__5 do
          rule /(\n|\r|\r\n)/, String
          rule /./, Comment
      end

      state:main__6 do
          rule /(\n|\r|\r\n)/, String
          rule /./, Comment
      end

      state:main__7 do
          rule /(\n|\r|\r\n)/, String
          rule /./, Comment
      end

      state:main__8 do
          rule /\b(not|alive|ignore|ajax|\d+m?s|alt|ever|\d+times|reverse|max\d+|min\d+|all|fragment|try\d+m?s|try|wait\d+m?s)\b/, Keyword::Pseudo
          rule /(\n|\r|\r\n)/, String
          rule /./, String
      end

      state:main__9 do
          rule /\b(now|if|else|for|filter|range|exists|while|do|any|emit|emitter|slot|assert|listen|wait|jammer|switch|case)\b/, Keyword
          rule /\b(bool|int|double|string|list|element|set|item|object|void|regex|datetime|session|window|cookie|tab|document|file|query|database|dbmanager|js-file|code-(icl|js|sql)|handle|any|type)\b/, Keyword::Type
          rule /\b(icL|Log|Tab|Document|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|State|DB|Query|DBManager|Code|Signal|Datetime)\b/, Name::Class
          rule /(\')(year|y|xPath|x|windows|window|width|visible|value|valid|url|typeName|typeId|tsv|title|texts?|teleport|tagName|tags?|tabs?|sum|sqrt2|source|silentMode|shift|session|selected|secure|second|scriptTimeout|screenshot|right|rects?|readOnly|rValue|quadratic|product|process|previous|pressTime|present|piDiv4|piDiv2|pi|path|partialLinkText|pageLoadTimeout|none|next|name|moveTime|month|minute|min|middle|max|log2e|log10e|ln2|ln10|linkText|link|linear|length|left|last|lValue|implicitTimeout|humanMode|httpOnly|hour|height|format|flashMode|first|expiry|enabled|empty|e|domain|document|day|current|cubic|ctrl|csv|css\-\w+|cssSelector|cookies|clickTime|clickable|capacity|bezier|attrs?\-\w+|alt|alert|2divSqrtPi|2divPi|1divSqrt2|1divPi)\b/ do
            groups Name, Name
          end
          rule /(\'props?\-)(wrap|willValidate|width|volume|videoWidth|videoHeight|valueAsNumber|value|validity|validationMessage|username|useMap|type|title|textLength|textContent|text|target|tagName|tHead|tFoot|tBodies|step|start|srclang|src|spellcheck|span|size|selectionStart|selectionEnd|selectionDirection|selectedOptions|selectedIndex|selected|seeking|search|scrollWidth|scrollTop|scrollLeft|scrollHeight|scope|rowSpan|rowIndex|reversed|required|rel|readyState|readOnly|protocol|previousElementSibling|preload|prefix|poster|position|port|playbackRate|placeholder|paused|pattern|pathname|password|parentElement|outerHTML|origin|options|offsetWidth|offsetTop|offsetParent|offsetLeft|offsetHeight|nodeValue|nodeType|nodeName|noValidate|noModule|nextElementSibling|networkState|naturalWidth|naturalHeight|name|muted|multiple|min|mediaGroup|media|maxLength|max|low|loop|localName|list|length|lastChild|lang|labels|label|kind|isMap|isContentEditable|isConnected|innerText|innerHTML|inert|index|indeterminate|id|httpEquiv|htmlFor|hreflang|href|hostname|host|high|hidden|height|hash|formTarget|formNoValidate|formMethod|formEnctype|formAction|form|firstChild|ended|enctype|encoding|elements|duration|draggable|download|disabled|disableRemotePlayback|dirName|dir|defer|defaultValue|defaultSelected|defaultPlaybackRate|defaultMuted|defaultChecked|default|dateTime|dataset|currentTime|currentSrc|crossOrigin|coords|controls|control|contentEditable|content|computedRole|computedName|complete|cols|colSpan|clientWidth|clientTop|clientLeft|clientHeight|className|cite|childNodes|checked|charset|cells|cellIndex|caption|baseURI|autoplay|autofocus|autocomplete|async|as|areas|alt|allowPaymentRequest|action|accessKeyLabel|accessKey|acceptCharset|accept|abbr)\b/ do
            groups Name, Name
          end
          rule /(\')([\w\-]+)/ do
            groups Punctuation, Name
          end
          rule /(sql)({)/ do
            groups Name::Function, Punctuation
            push :main__1
          end
          rule /(icl)(:pro)?({)/ do
            groups Name::Function, Keyword::Pseudo, Punctuation
          end
          rule /(\.)(write|type|trim|toUpperCase|toUTC|toTimeZone|toPrev|toNext|toLowerCase|toLast|toFirst|tan|sync|switchToParent|switchToFrame|switchToDefault|switchTo|superClick|substring|state|stack|split|sort|sin|setup|setProcess|setAsUserScript|setAsPersistentUserScript|set|sendKeys|seek|secsTo|screenshot|save|runAsync|run|round|rightJustified|right|return|restoreProcess|restore|resetTime|replaceInStrings|replace|removeOne|removeLast|removeFirst|removeField|removeDuplicates|removeAt|removeAll|remove|refresh|radiansToDegrees|queryTags|queryTag|queryLinks|queryLink|queryByXPath|queryAllByXPath|queryAll|query|process|previous|prev|prepend|paste|parent|out|openSQLite|open|none|next|newAtEnd|new|move|mouseUp|mouseDown|minimize|min|mid|maximize|max|markTest|markStep|loadTSV|loadCSV|load|ln|listen|leftJustified|left|lastIndexOf|last|kill|keyUp|keyPress|keyDown|join|insertField|insert|info|indexOf|image|ignore|hover|hasField|handle|getRowsAffected|getLength|getField|getError|get|functions|fullscreen|forward|forceType|forceClick|focus|floor|first|findByTitle|find|filter|fastType|exp|exec|error|ensureRValue|endsWith|dismiss|destroy|deleteAll|delete|degreesToRadians|deactivate|daysTo|currentUTC|current|createPath|createDir|create|count|cos|copy|continue|contains|connect|compare|closest|closeToRight|closeToLeft|closeOthers|closeByTitle|closeAll|close|clone|click|clear|child|ceil|break|beginsWith|back|atan|at|asin|applicate|append|all|addYears|addSecs|addMonths|addDescription|addDays|add|activate|acos|accept)\b/ do
            groups Name::Function, Name::Function
          end
          rule /\b(emit|slot)(:\w+)\b/ do
            groups Keyword, Keyword::Pseudo
          end
          rule /\b(css)(:all|:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation
            push :main__2
          end
          rule /\b(xpath)(:all|:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(link)(:fragment|:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(links)(:fragment)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(tag|button|input|field|h[1-6]|legend|span)(:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(tags)(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(web)(\[\])/ do
            groups Name::Function, Punctuation
          end
          rule /\b(js)(:value)?(@\w*)?({)/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation
            push :main__3
          end
          rule /\b(js)(:file)(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Punctuation, String, Punctuation
          end
          rule /(\$\w+)/, Name::Function
          rule /(@\w*)/, Name::Variable
          rule /(#\w+)/, Name::Variable::Global
          rule /(#)/, Name::Variable
          rule /(\{:)(\w+)\b/ do
            groups Punctuation, Name
          end
          rule /(:)(not|alive|ignore|ajax|\d+m?s|alt|ever|\d+times|reverse|max\d+|min\d+|all|fragment|try\d+m?s|try|wait\d+m?s)\b/ do
            groups Keyword::Pseudo, Keyword::Pseudo
          end
          rule /\b(\d+\.?\d*?)\b/, Number
          rule /(\/\/.*?\/\/|\/:.*?:\/|\/!.*?\!\/|\/".*?"\/)(\w*)/ do
            groups String::Regex, String::Regex
          end
          rule /\b(sessions|windows|tabs|cookies|alert|tabs|css|xpath|links?|tags?|button|input|field|web|h[1-6]|legend|span)\b/, Generic::Error
          rule /(\")/, String, :main__4
          rule /(```)/, Comment, :main__5
          rule /(``)/, Comment, :main__6
          rule /(`)/, Comment, :main__7
          rule /(:\[)/, Punctuation, :main__8
          rule /(\[)/, Operator, :main__9
          rule /(;)/, Punctuation
          rule /(:\!|::|:\*|:\?|&|\||~|^|%|==|\!=|>=|<=|<>|<=>|><|>=<|<<|\!<|<\*|\!\*|\*\*|\/'|\!|>|<|\+|\-|\*|\/|\\|:|\(|\)|\=|\,|\[|\])/, Operator
          rule /(\w+)/, Name
          rule /(\n|\r|\r\n)/, String
          rule /./, String
      end

      state:webElement__1 do
          rule /(\.[\w\-\_]+)/, Name::Class
          rule /(\#[\w\-\_]+)/, Name::Variable::Instance
          rule /(\:[\w\-\_]+)(\s*\()/ do
            groups Name::Function, Punctuation
          end
          rule /(\:[\w\-\_]+)/, Name
          rule /\b([\w\-\_]+)(=[^\w\n\r]?)([\w\-\_]+)/ do
            groups Name, Punctuation, String
          end
          rule /\b(\d+)\b/, Number
          rule /\b([\w\-\_]+)\b/, Keyword::Type
          rule /(\[)/, Punctuation, :webElement__1
          rule /(\n|\r|\r\n)/, String
          rule /./, String
      end

    end
  end
end

