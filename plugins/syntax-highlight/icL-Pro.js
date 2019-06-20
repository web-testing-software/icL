/*
* To try in Ace editor, copy and paste into the mode creator
* here : http://ace.c9.io/tool/mode_creator.html
*/

define(function(require, exports, module) {
"use strict";
var oop = require("../lib/oop");
var TextHighlightRules = require("./text_highlight_rules").TextHighlightRules;
/* --------------------- START ----------------------------- */
var IclHighlightRules = function() {
this.$rules = {
"start" : [
   {
      "token" : "keyword",
      "regex" : "\\b(now|if|else|for|filter|range|exists|while|do|any|emit|emiter|slot|assert|listen|wait|jammer|switch|case)\\b"
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
      "token" : "variable.other.member",
      "regex" : "(\\'[\\w\\-\\*]+)"
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
      "token" : "entity.name.function",
      "regex" : "(\\.\\w+)"
   },
   {
      "token" : ["keyword", "entity.name.tag"],
      "regex" : "\\b(emit|slot)(:\\w+)\\b"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation"],
      "regex" : "\\b(css)(:all|:try|:try\\d+m?s|:wait\\d+m?s)?(@\\w*)?(\\[)",
      "push" : "main__2"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(xpath)(:all|:try|:try\\d+m?s|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(link)(:fragment|:try|:try\\d+m?s|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(links)(:fragment)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(tag|button|input|field|h[1-6]|legend|span)(:try|:try\\d+m?s|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
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
      "token" : ["entity.name.tag", "entity.name.tag"],
      "regex" : "(:)(not|alive|ignore|ajax|\\d+m?s|alt|ever|\\d+times|reverse|max\\d+|min\\d+|all|fragment|try\\d+m?s|try|wait\\d+m?s)\\b"
   },
   {
      "token" : "constant.numeric",
      "regex" : "\\b(\\d+\\.?\\d*?)\\b"
   },
   {
      "token" : ["string.regexp", "string.regexp"],
      "regex" : "(//.*?//|/:.*?:/|/\\$.*?\\$/|/\".*?\"/)(\\w*)"
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
      "token" : "punctuation",
      "regex" : "(\\[)",
      "push" : "main__9"
   },
   {
      "token" : "punctuation",
      "regex" : "(;)"
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
      "token" : "keyword",
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
      "token" : "keyword",
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
      "token" : "keyword",
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
      "token" : "punctuation",
      "regex" : "(\\])",
      "next" : "pop"
   },
   {
      "token" : "keyword",
      "regex" : "\\b(now|if|else|for|filter|range|exists|while|do|any|emit|emiter|slot|assert|listen|wait|jammer|switch|case)\\b"
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
      "token" : "variable.other.member",
      "regex" : "(\\'[\\w\\-\\*]+)"
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
      "token" : "entity.name.function",
      "regex" : "(\\.\\w+)"
   },
   {
      "token" : ["keyword", "entity.name.tag"],
      "regex" : "\\b(emit|slot)(:\\w+)\\b"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation"],
      "regex" : "\\b(css)(:all|:try|:try\\d+m?s|:wait\\d+m?s)?(@\\w*)?(\\[)",
      "push" : "main__2"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(xpath)(:all|:try|:try\\d+m?s|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(link)(:fragment|:try|:try\\d+m?s|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(links)(:fragment)?(@\\w*)?(\\[)(.*?)(\\])"
   },
   {
      "token" : ["entity.name.function", "entity.name.tag", "variable.other", "punctuation", "string.quoted.single", "punctuation"],
      "regex" : "\\b(tag|button|input|field|h[1-6]|legend|span)(:try|:try\\d+m?s|:wait\\d+m?s)?(@\\w*)?(\\[)(.*?)(\\])"
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
      "token" : ["entity.name.tag", "entity.name.tag"],
      "regex" : "(:)(not|alive|ignore|ajax|\\d+m?s|alt|ever|\\d+times|reverse|max\\d+|min\\d+|all|fragment|try\\d+m?s|try|wait\\d+m?s)\\b"
   },
   {
      "token" : "constant.numeric",
      "regex" : "\\b(\\d+\\.?\\d*?)\\b"
   },
   {
      "token" : ["string.regexp", "string.regexp"],
      "regex" : "(//.*?//|/:.*?:/|/\\$.*?\\$/|/\".*?\"/)(\\w*)"
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
      "token" : "punctuation",
      "regex" : "(\\[)",
      "push" : "main__9"
   },
   {
      "token" : "punctuation",
      "regex" : "(;)"
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
oop.inherits(IclHighlightRules, TextHighlightRules);
exports.IclHighlightRules = IclHighlightRules;
});
