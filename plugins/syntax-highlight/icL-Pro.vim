" Vim syntax file
" Language:	icL
" Maintainer:	Lelițac Vasile <lixcode@vivaldi.net>
" Last Change:	2019/06/23
" Version:      1.4

" This file is part of icL (intra-cloud Lightning)
" 
" Author: Lelițac Vasile <lixcode@vivaldi.net>
" Copyright (C) 2019 Lelițac Vasile
"
" icL is free software; you can redistribute it and/or
" modify it under the terms of the GNU Lesser General Public
" License as published by the Free Software Foundation; either
" version 3.0 of the License, or (at your option) any later version.
"
" GtkSourceView is distributed in the hope that it will be useful,
" but WITHOUT ANY WARRANTY; without even the implied warranty of
" MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
" Lesser General Public License for more details.
"
" You should have received a copy of the GNU Lesser General Public
" License along with this library; if not, write to the Free Software
" Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
"
" NOTES
"
" This file hightlights icL-Pro 1.4 files
" Lexer: http://web-testing.software/standard/icL-Pro/1.4/en.html
" Lexer: http://web-testing.software/standard/icL-Pro/1.4/en-dark.html 

if !exists("main_syntax")
  " quit when a syntax file was already loaded
  if exists("b:current_syntax")
    finish
  endif
  let main_syntax = 'icL'
endif

"let s:cpo_save = &cpo
"set cpo&vim

syntax match keyword "\(now\|if\|else\|for\|filter\|range\|exists\|while\|do\|any\|emit\|emitter\|slot\|assert\|listen\|wait\|jammer\|switch\|case\)"

syntax match metatype "\b(bool|int|double|string|list|element|set|item|object|void|regex|datetime|session|window|cookie|tab|document|file|query|database|dbmanager|js-file|code-(icl|js|sql)|handle|any|type)\b"

syntax match metaclass "\b(icL|Log|Tab|Document|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|State|DB|Query|DBManager|Code|Signal|Datetime)\b"

syntax match property "(\')(year|y|xPath|x|windows|window|width|visible|value|valid|url|typeName|typeId|tsv|title|texts?|teleport|tagName|tags?|tabs?|sum|sqrt2|source|silentMode|shift|session|selected|secure|second|scriptTimeout|screenshot|right|rects?|readOnly|rValue|quadratic|product|process|previous|pressTime|present|piDiv4|piDiv2|pi|path|partialLinkText|pageLoadTimeout|none|next|name|moveTime|month|minute|min|middle|max|log2e|log10e|ln2|ln10|linkText|link|linear|length|left|last|lValue|implicitTimeout|humanMode|httpOnly|hour|height|format|flashMode|first|expiry|enabled|empty|e|domain|document|day|current|cubic|ctrl|csv|css\-\w+|cssSelector|cookies|clickTime|clickable|capacity|bezier|attrs?\-\w+|alt|alert|2divSqrtPi|2divPi|1divSqrt2|1divPi)\b"

syntax match property "(\'props?\-)(wrap|willValidate|width|volume|videoWidth|videoHeight|valueAsNumber|value|validity|validationMessage|username|useMap|type|title|textLength|textContent|text|target|tagName|tHead|tFoot|tBodies|step|start|srclang|src|spellcheck|span|size|selectionStart|selectionEnd|selectionDirection|selectedOptions|selectedIndex|selected|seeking|search|scrollWidth|scrollTop|scrollLeft|scrollHeight|scope|rowSpan|rowIndex|reversed|required|rel|readyState|readOnly|protocol|previousElementSibling|preload|prefix|poster|position|port|playbackRate|placeholder|paused|pattern|pathname|password|parentElement|outerHTML|origin|options|offsetWidth|offsetTop|offsetParent|offsetLeft|offsetHeight|nodeValue|nodeType|nodeName|noValidate|noModule|nextElementSibling|networkState|naturalWidth|naturalHeight|name|muted|multiple|min|mediaGroup|media|maxLength|max|low|loop|localName|list|length|lastChild|lang|labels|label|kind|isMap|isContentEditable|isConnected|innerText|innerHTML|inert|index|indeterminate|id|httpEquiv|htmlFor|hreflang|href|hostname|host|high|hidden|height|hash|formTarget|formNoValidate|formMethod|formEnctype|formAction|form|firstChild|ended|enctype|encoding|elements|duration|draggable|download|disabled|disableRemotePlayback|dirName|dir|defer|defaultValue|defaultSelected|defaultPlaybackRate|defaultMuted|defaultChecked|default|dateTime|dataset|currentTime|currentSrc|crossOrigin|coords|controls|control|contentEditable|content|computedRole|computedName|complete|cols|colSpan|clientWidth|clientTop|clientLeft|clientHeight|className|cite|childNodes|checked|charset|cells|cellIndex|caption|baseURI|autoplay|autofocus|autocomplete|async|as|areas|alt|allowPaymentRequest|action|accessKeyLabel|accessKey|acceptCharset|accept|abbr)\b"

syntax match property "(\')([\w\-]+)"

syntax region codeliteral start="(sql)({)" end="(})" contains=sqlkeyword,sqllvar,sqlfun

syntax region codeliteral start="(icl)(:pro)?({)" end="(})"

syntax match method "(\.)(write|type|trim|toUpperCase|toUTC|toTimeZone|toPrev|toNext|toLowerCase|toLast|toFirst|tan|sync|switchToParent|switchToFrame|switchToDefault|switchTo|superClick|substring|state|stack|split|sort|sin|setup|setProcess|setAsUserScript|setAsPersistentUserScript|set|sendKeys|seek|secsTo|screenshot|save|runAsync|run|round|rightJustified|right|return|restoreProcess|restore|resetTime|replaceInStrings|replace|removeOne|removeLast|removeFirst|removeField|removeDuplicates|removeAt|removeAll|remove|refresh|radiansToDegrees|queryTags|queryTag|queryLinks|queryLink|queryByXPath|queryAllByXPath|queryAll|query|process|previous|prev|prepend|paste|parent|out|openSQLite|open|none|next|newAtEnd|new|move|mouseUp|mouseDown|minimize|min|mid|maximize|max|markTest|markStep|loadTSV|loadCSV|load|ln|listen|leftJustified|left|lastIndexOf|last|kill|keyUp|keyPress|keyDown|join|insertField|insert|info|indexOf|image|ignore|hover|hasField|handler|getRowsAffected|getLength|getField|getError|get|functions|fullscreen|forward|forceType|forceClick|focus|floor|first|findByTitle|find|filter|fastType|exp|exec|error|ensureRValue|endsWith|dismiss|destroy|deleteAll|delete|degreesToRadians|deactivate|daysTo|currentUTC|current|crossfire|createPath|createDir|create|count|cos|copy|continue|contains|connect|compare|closest|closeToRight|closeToLeft|closeOthers|closeByTitle|closeAll|close|clone|click|clear|child|ceil|break|beginsWith|back|atan|at|asin|applicate|append|all|addYears|addSecs|addMonths|addDescription|addDays|add|activate|acos|accept)\b"

syntax match modifier "(?<=\b(emit|slot))(:\w+)\b"

syntax region codeliteral oneline start="\b(css)(:all|:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)" end="(\])" contains=cssclass,cssid,cssfunc,cssstate,cssprop,cssstr,cssnumber,csstag,cssin

syntax region codeliteral oneline start="\b(xpath)(:all|:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)" end="(\])" contains=anystring
syntax region codeliteral oneline start="\b(link)(:fragment|:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)" end="(\])" contains=anystring
syntax region codeliteral oneline start="\b(links)(:fragment)?(@\w*)?(\[)" end="(\])" contains=anystring
syntax region codeliteral oneline start="\b(tag|button|input|field|h[1-6]|legend|span)(:try\d+m?s|:try|:wait\d+m?s)?(@\w*)?(\[)" end="(\])" contains=anystring
syntax region codeliteral oneline start="\b(tags)(@\w*)?(\[)" end="(\])" contains=anystring

syntax match anystring "." contained

syntax match codeliteral "\b(web)(?=\[\])"

syntax region codeliteral start="\b(js)(:value)?(@\w*)?({)" end="(})" contains=jskeyword,jscrossfire,jsmethod,jsfunction,jsprop,jsclass,jsin

syntax region codeliteral oneline start="\b(js)(:file)(\[)" end="(\])" contains=anystring

syntax match function "(\$\w+)"

syntax match lvariable "(@\w*)"

syntax match gvariable "(#\w+)"

syntax match lvariable "(#)"

syntax match property "(?<={:)(\w+)\b"

syntax match modifier "(:)(not|alive|ignore|ajax|\d+m?s|alt|ever|\d+times|reverse|max\d+|min\d+|all|fragment|try\d+m?s|try|wait\d+m?s)\b"

syntax match numeric "\b(\d+\.?\d*?)\b"

syntax match regex "(//.*?//|/:.*?:/|/!.*?\!/|/\".*?\"/)(\w*)"

syntax match illegal "\b(sessions|windows|tabs|cookies|alert|tabs|css|xpath|links?|tags?|button|input|field|web|h[1-6]|legend|span)\b"

syntax region string oneline start=/"/ skip=/\\"/ end=/"/
"
syntax region comment start="```" end="```"
syntax region comment oneline start="``" end="$"
syntax region comment oneline start="`" end="`"

syntax region modifiers start="(:\[)" end="(\])" contains=clearmodifier

syntax match clearmodifier "\b(not|alive|ignore|ajax|\d+m?s|alt|ever|\d+times|reverse|max\d+|min\d+|all|fragment|try\d+m?s|try|wait\d+m?s)\b" contained

syntax region object start="\[" end="\]" contains=comment,keyword,numeric,punctuation,illegal,metatype,metaclass,property,codeliteral,modifier,modifiers,method,lvariable,gvariable,string,function,regex,operator,identifier

syntax match identifier /\w+/ contained

syntax match punctuation ";"

"----------------------------------------------------

"syntax match name regex
"syntax region name oneline start="" skip="" end=""
"syntax region name start="" end=""

"CSS subclasses"

syntax match cssclass "(\.[\w\-\_]+)" contained
syntax match cssid "(\#[\w\-\_]+)" contained
syntax match cssfunc "(\:[\w\-\_]+)(?=\s*\(.*\))" contained
syntax match cssstate "(\:[\w\-\_]+)" contained
syntax match cssprop "(?&lt;=\[)([\w\-\_]+)(?==)" contained
syntax match cssstr "(?&lt;=)([\w\-\_]+)(?=\])" contained
syntax match cssnumber "\b(\d+)\b" contained
syntax match csstag "\b([\w\-\_]+)\b" contained
syntax region cssin start="\[" end="\]" contained contains=cssclass,cssid,cssfunc,cssstate,cssprop,cssstr,cssnumber,csstag,cssin

"SQL"

syntax match sqlkeyword "\b(SELECT|FROM|WHERE|LIMIT|INSERT|INTO|VALUE)\b"
syntax match sqllvar "(@?:[\w\_]+)"
syntax match sqlgvar "(#:[\w\_]+)"
syntax match sqlfun "([\w\_]+)(?=\s*\(.*\))"

"JavaScript"

syntax match jskeyword "\b(abstract|arguments|await|boolean|break|byte|case|catch|char|class|const|continue|debugger|default|delete|do|double|else|enum|eval|export|extends|false|final|finally|float|for|function|goto|if|implements|import|in|instanceof|int|interface|let|long|native|new|null|package|private|protected|public|return|short|static|super|switch|synchronized|this|throw|throws|transient|true|try|typeof|var|void|volatile|while|with|yield)\b" contained
syntax match jscrossfire "(\${[\w\_]+})" contained
syntax match jsmethod "(\.[\w\_]+)(?=\s*\(.*\))" contained
syntax match jsfunction "(\b[\w\_]+)(?=\s*\(.*\))" contained
syntax match jsprop "(\.[\w\_]+)" contained
syntax match jsclass "\b(window|document|crossfire)\b" contained
syntax region jsin start="{" end="}" contained contains=jskeyword,jscrossfire,jsmethod,jsfunction,jsprop,jsclass,jsin

"hightlights linking"

hi def link keyword 	  		Keyword
hi def link metatype 		Type
hi def link metaclass 		Structure
hi def link property 		PreProc
hi def link codeliteral		Statement
hi def link method 			function
hi def link anystring		string
hi def link function 		Function
hi def link lvariable		Identifier
hi def link gvariable		Include
hi def link modifier			PreCondit
hi def link modifiers		modifier
hi def link clearmodifier	modifier
hi def link numeric 			Number
hi def link regex 			String
hi def link illegal 			Error
hi def link string 			String
hi def link comment 			Comment
hi def link object 			Operator
hi def link identifier 		property
hi def link punctuation 	Operator

"End of syntax"

let b:current_syntax = "icL"
if main_syntax == 'icL'
  unlet main_syntax
endif
"let &cpo = s:cpo_save
"unlet s:cpo_save

" Vim settings
" vim: ts=3
