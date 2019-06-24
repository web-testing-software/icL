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

"---------------------------------------------"

syntax match punctuation ";"

syntax match identifier "\w\+" contained

syntax region iFold start="{" end="}" transparent contains=TOP fold

syntax region object start="\[" end="\]" transparent contains=TOP fold

syntax match digits "\d\+" contained

syntax match clearmodifier "\<\(not\|alive\|ignore\|ajax\|\d\+m\?s\|alt\|ever\|\d\+times\|reverse\|max\d\+\|min\d\+\|all\|fragment\|try\d\+m\?s\|try\|wait\d\+m\?s\)\>" contained contains=digits

syntax region modifiers start=":\[" end="\]" contains=clearmodifier

syntax region comment oneline start="`" end="`"
syntax region comment oneline start="``" end="$"
syntax region comment start="```" end="```"
"
syntax region string oneline start=+"+ skip=+\\"+ end=+"+

syntax match illegal "\<\(sessions\|windows\|tabs\|cookies\|alert\|css\|xpath\|links\?\|tags\?\|button\|input\|field\|web\|h[123456]\|legend\|span\)\>"

syntax match regex "\(//.*//\|/:.*:/\|/!.*!/\|/\".*\"/\)\w*"

syntax match numeric "\<\(\d\+.\?\d*\)\>"

syntax match modifier ":\(not\|alive\|ignore\|ajax\|\d\+m\?s\|alt\|ever\|\d\+times\|reverse\|max\d\+\|min\d\+\|all\|fragment\|try\d\+m\?s\|try\|wait\d\+m\?s\)\>" contains=digits

syntax match lvariable "#"

syntax match gvariable "#\w\+"

syntax match lvariable "@\w*"

syntax match function "$\w\+"

syntax region codeliteral oneline start="\<\(js\)\(:file\)\[" end="\]" contains=anystring

syntax region codeliteral keepend start="\<\(js\)\(:value\)\?\(@\w*\)\?{"rs=e+1 end="}"re=s-1 contains=jskeyword,jscrossfire,jsfunction,jsprop,jsclass,jsin fold

syntax match codeliteral "\<\(web\)\>"

syntax region anystring start="\[" end="\]" contained contains=anychar transparent
syntax match anychar "[^\[\]]" contained
syntax match anyel "\<\(tags\?\|button\|input\|field\|h[1-6]\|legend\|span\|links\?\|xpath\)\>" contained
syntax match anymodifier "\(:all\|:fragment\|:try\d\+m\?s\|:try\|:wait\d\+m\?s\)\>" contains=digits

syntax region codeliteral oneline keepend start="\<\(tags\)\(@\w*\)\?\[" end="\]" contains=anystring,csslvariable,anyel,anymodifier
syntax region codeliteral oneline keepend start="\<\(tag\|button\|input\|field\|h[1-6]\|legend\|span\)\(:try\d\+m\?s\|:try\|:wait\d\+m\?s\)\?\(@\w*\)\?\[" end="\]" contains=anystring,csslvariable,anyel,anymodifier
syntax region codeliteral oneline keepend start="\<links\(:fragment\)\?\(@\w*\)\?\[" end="\]" contains=anystring,csslvariable,anyel,anymodifier
syntax region codeliteral oneline keepend start="\<\(link\)\?\(@\w*\)\?\(\[\)" end="\]" contains=anystring,csslvariable,anyel,anymodifier
syntax region codeliteral oneline keepend start="\<xpath\(:all\|:try\d\+m\?s\|:try\|:wait\d\+m\?s\)\?\(@\w*\)\?\[" end="\]" contains=anystring,csslvariable,anyel,anymodifier

syntax region codeliteral oneline keepend start="\<css\(:all\|:try\d\+m\?s\|:try\|:wait\d\+m\?s\)\?\(@\w*\)\?\[" end="\]" contains=cssclass,cssid,cssstate,cssnumber,csstag,cssliteral,cssmodifier,csslvariable

syntax match cssliteral "\<css\>" contained
syntax match cssmodifier "\(:all\|:try\d\+m\?s\|:try\|:wait\d\+m\?s\)" contained contains=digits
syntax match csslvariable "@\w*" contained


syntax match method "\(.\)\(write\|type\|trim\|toUpperCase\|toUTC\|toTimeZone\|toPrev\|toNext\|toLowerCase\|toLast\|toFirst\|tan\|sync\|switchToParent\|switchToFrame\|switchToDefault\|switchTo\|superClick\|substring\|state\|stack\|split\|sort\|sin\|setup\|setProcess\|setAsUserScript\|setAsPersistentUserScript\|set\|sendKeys\|seek\|secsTo\|screenshot\|save\|runAsync\|run\|round\|rightJustified\|right\|return\|restoreProcess\|restore\|resetTime\|replaceInStrings\|replace\|removeOne\|removeLast\|removeFirst\|removeField\|removeDuplicates\|removeAt\|removeAll\|remove\|refresh\|radiansToDegrees\|queryTags\|queryTag\|queryLinks\|queryLink\|queryByXPath\|queryAllByXPath\|queryAll\|query\|process\|previous\|prev\|prepend\|paste\|parent\|out\|openSQLite\|open\|none\|next\|newAtEnd\|new\|move\|mouseUp\|mouseDown\|minimize\|min\|mid\|maximize\|max\|markTest\|markStep\|loadTSV\|loadCSV\|load\|ln\|listen\|leftJustified\|left\|lastIndexOf\|last\|kill\|keyUp\|keyPress\|keyDown\|join\|insertField\|insert\|info\|indexOf\|image\|ignore\|hover\|hasField\|handle\|getRowsAffected\|getLength\|getField\|getError\|get\|functions\|fullscreen\|forward\|forceType\|forceClick\|focus\|floor\|first\|findByTitle\|find\|filter\|fastType\|exp\|exec\|error\|ensureRValue\|endsWith\|dismiss\|destroy\|deleteAll\|delete\|degreesToRadians\|deactivate\|daysTo\|currentUTC\|current\|crossfire\|createPath\|createDir\|create\|count\|cos\|copy\|continue\|contains\|connect\|compare\|closest\|closeToRight\|closeToLeft\|closeOthers\|closeByTitle\|closeAll\|close\|clone\|click\|clear\|child\|ceil\|break\|beginsWith\|back\|atan\|at\|asin\|applicate\|append\|all\|addYears\|addSecs\|addMonths\|addDescription\|addDays\|add\|activate\|acos\|accept\)\>"

syntax region codeliteral start="\<\(icl\)\(:pro\)\?{" end="}" contains=promodifier
syntax match promodifier ":pro" contained 

syntax region codeliteral start="\<\(sql\){" end="}" contains=sqlkeyword,sqllvar,sqlfun

syntax match property "'props\?\-\(wrap\|willValidate\|width\|volume\|videoWidth\|videoHeight\|valueAsNumber\|value\|validity\|validationMessage\|username\|useMap\|type\|title\|textLength\|textContent\|text\|target\|tagName\|tHead\|tFoot\|tBodies\|step\|start\|srclang\|src\|spellcheck\|span\|size\|selectionStart\|selectionEnd\|selectionDirection\|selectedOptions\|selectedIndex\|selected\|seeking\|search\|scrollWidth\|scrollTop\|scrollLeft\|scrollHeight\|scope\|rowSpan\|rowIndex\|reversed\|required\|rel\|readyState\|readOnly\|protocol\|previousElementSibling\|preload\|prefix\|poster\|position\|port\|playbackRate\|placeholder\|paused\|pattern\|pathname\|password\|parentElement\|outerHTML\|origin\|options\|offsetWidth\|offsetTop\|offsetParent\|offsetLeft\|offsetHeight\|nodeValue\|nodeType\|nodeName\|noValidate\|noModule\|nextElementSibling\|networkState\|naturalWidth\|naturalHeight\|name\|muted\|multiple\|min\|mediaGroup\|media\|maxLength\|max\|low\|loop\|localName\|list\|length\|lastChild\|lang\|labels\|label\|kind\|isMap\|isContentEditable\|isConnected\|innerText\|innerHTML\|inert\|index\|indeterminate\|id\|httpEquiv\|htmlFor\|hreflang\|href\|hostname\|host\|high\|hidden\|height\|hash\|formTarget\|formNoValidate\|formMethod\|formEnctype\|formAction\|form\|firstChild\|ended\|enctype\|encoding\|elements\|duration\|draggable\|download\|disabled\|disableRemotePlayback\|dirName\|dir\|defer\|defaultValue\|defaultSelected\|defaultPlaybackRate\|defaultMuted\|defaultChecked\|default\|dateTime\|dataset\|currentTime\|currentSrc\|crossOrigin\|coords\|controls\|control\|contentEditable\|content\|computedRole\|computedName\|complete\|cols\|colSpan\|clientWidth\|clientTop\|clientLeft\|clientHeight\|className\|cite\|childNodes\|checked\|charset\|cells\|cellIndex\|caption\|baseURI\|autoplay\|autofocus\|autocomplete\|async\|as\|areas\|alt\|allowPaymentRequest\|action\|accessKeyLabel\|accessKey\|acceptCharset\|accept\|abbr\)\>"

syntax match property "'\(year\|y\|xPath\|x\|windows\|window\|width\|visible\|value\|valid\|url\|typeName\|typeId\|tsv\|title\|texts\?\|teleport\|tagName\|tags\?\|tabs\?\|sum\|sqrt2\|source\|silentMode\|shift\|session\|selected\|secure\|second\|scriptTimeout\|screenshot\|right\|rects\?\|readOnly\|rValue\|quadratic\|product\|process\|previous\|pressTime\|present\|piDiv4\|piDiv2\|pi\|path\|partialLinkText\|pageLoadTimeout\|none\|next\|name\|moveTime\|month\|minute\|min\|middle\|max\|log2e\|log10e\|ln2\|ln10\|linkText\|link\|linear\|length\|left\|last\|lValue\|implicitTimeout\|humanMode\|httpOnly\|hour\|height\|format\|flashMode\|first\|expiry\|enabled\|empty\|e\|domain\|document\|day\|current\|cubic\|ctrl\|csv\|css\-\w\+\|cssSelector\|cookies\|clickTime\|clickable\|capacity\|bezier\|attrs\?\-\w\+\|alt\|alert\|2divSqrtPi\|2divPi\|1divSqrt2\|1divPi\)\>"

syntax match metaclass "\<\(icL\|Log\|Tab\|Document\|Import\|true\|false\|Numbers\|Types\|Key\|Alert\|By\|DSV\|Sessions\?\|Windows\?\|Cookies\|Tabs\?\|Files\?\|Make\|Math\|Wait\|Mouse\|Move\|Stacks\?\|State\|DB\|Query\|DBManager\|Code\|Signal\|Datetime\)\>"

syntax match metatype "\<\(bool\|int\|double\|string\|list\|element\|set\|item\|object\|void\|regex\|datetime\|session\|window\|cookie\|tab\|document\|file\|query\|database\|dbmanager\|js-file\|code-\(icl\|js\|sql\)\|handler\|any\|type\)\>"

syntax match keyword "\<\(now\|if\|else\|for\|filter\|range\|exists\|while\|do\|any\|emit\|emitter\|slot\|assert\|listen\|wait\|jammer\|switch\|case\)\>"

syntax match modifier "'\w\+\>"hs=s+1

"----------------------------------------------------

"syntax match name regex
"syntax region name oneline start="" skip="" end=""
"syntax region name start="" end=""

"CSS subclasses"

syntax match csstag "\w\+" contained
syntax match cssclass ".\w\+\>"he=e contained
syntax match cssid "#\w\+\>"he=e contained
syntax match cssstate ":\w\+\>"he=e contained
syntax match cssnumber "\(\d\+\)"he=e contained


"SQL"

syntax match sqlkeyword "\<\(SELECT\|FROM\|WHERE\|LIMIT\|INSERT\|INTO\|VALUE\)\>" contained
syntax match sqllvar "@\?:[\w]\+" contained
syntax match sqlgvar "#:[\w]\+" contained
syntax region sqlfun start="[\w_]\+\_s*(" end=")" contained contains=sqlkeyword,sqllvar,sqlgvar,sqlfun

"JavaScript"

syntax region jsin extend start="{" end="}" contained contains=jskeyword,jscrossfire,jsfunction,jsprop,jsclass,jsin
syntax match jskeyword "\<\(abstract\|arguments\|await\|boolean\|break\|byte\|case\|catch\|char\|class\|const\|continue\|debugger\|default\|delete\|do\|double\|else\|enum\|eval\|export\|extends\|false\|final\|finally\|float\|for\|function\|goto\|if\|implements\|import\|in\|instanceof\|int\|interface\|let\|long\|native\|new\|null\|package\|private\|protected\|public\|return\|short\|static\|super\|switch\|synchronized\|this\|throw\|throws\|transient\|true\|try\|typeof\|var\|void\|volatile\|while\|with\|yield\)\>" contained
syntax match jscrossfire "\(${[\w_]\+}\)" contained
syntax match jsprop "\.[\w_]\+" contained
syntax match jsclass contained "\<\(window\|document\|crossfire\)\>"
syntax region jsfunction start="\<\.\?[\w_]\+\_s*(" end=")" contained contains=jskeyword,jscrossfire,jsfunction,jsprop,jsclass,jsin
syntax match jsend "}"

"hightlights linking"

hi def link anyel				codeliteral
hi def link anymodifier		modifier
hi def link anybrackets		operator
hi def link cssliteral		codeliteral
hi def link cssmodifier		modifier
hi def link csstag			Type
hi def link cssclass			Include
hi def link cssid 			Identifier
hi def link cssnumber		numeric
hi def link cssfunc			function
hi def link sqlkeyword		keyword
hi def link sqllvar			lvariable
hi def link sqlgvar			gvariable
hi def link sqlfun			function
hi def link jskeyword		keyword
hi def link jscrossfire		function
hi def link jsprop			property
hi def link jsclass			metaclass
hi def link jsfunction		function
hi def link cssprop			property
hi def link cssvalue			string
hi def link csslvariable	lvariable
hi def link cssstate			metatype
hi def link keyword 	  		Keyword
hi def link metatype 		Type
hi def link metaclass 		Structure
hi def link property 		PreProc
hi def link codeliteral		Statement
hi def link method 			function
hi def link anychar			string
hi def link function 		Function
hi def link lvariable		Identifier
hi def link gvariable		Include
hi def link modifier			PreCondit
hi def link modifiers		modifier
hi def link clearmodifier	modifier
hi def link numeric 			Number
hi def link digits			numeric
hi def link regex 			String
hi def link illegal 			Error
hi def link string 			String
hi def link comment 			Comment
hi def link object 			Operator
hi def link identifier 		property
hi def link punctuation 	Operator
hi def link promodifier		modifier

"End of syntax"

let b:current_syntax = "icL"
if main_syntax == 'icL'
  unlet main_syntax
endif
"let &cpo = s:cpo_save
"unlet s:cpo_save

" Vim settings
" vim: ts=3
