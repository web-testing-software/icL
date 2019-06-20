import re

from pygments.lexer import RegexLexer, bygroups
from pygments.token import *

__all__ = ['IclLexer']

class IclLexer(RegexLexer):
    name = 'icL'
    aliases = ['icl']
    filenames = ['*.icL', '*.icL-Pro']
    
    flags = re.MULTILINE | re.DOTALL

    tokens = {

        'root': [

            (r'\b(now|if|else|for|filter|range|exists|while|do|any|emit|emiter|slot|assert|listen|wait|jammer|switch|case)\b',
                Keyword),
            
            (r'\b(bool|int|double|string|list|element|set|item|object|void|regex|datetime|session|window|cookie|tab|document|file|query|database|dbmanager|js-file|code-(icl|js|sql)|handler|any|type)\b',
                Keyword.Type),
            
            (r'\b(sessions|windows|tabs|cookies|alert|tabs)\b', 
                Name.Label),

            (r'\b(icL|Log|Tab|Document|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|State|DB|Query|DBManager|Code|Signal|Datetime)\b', 
                Name.Class),

            (r'\'[\w\-\*]+', 
                Name.Property),

            (r'(sql)(\{)',
                bygroups(Name.Function,
                    Text),
                'sql_code'),

            (r'(icl)(:pro)?({)',
                bygroups(Name.Function,
                    Keyword.Pseudo,
                    Text)),

            (r'\.\w+', 
                Name.Function),

            (r'\b(emit|slot)(:\w+)\b',
                bygroups(Keyword,
                    Name.Exception)),

            (r'\b(css)(:all|:try|:try[\dX]+m?s?|:wait[\dX]+m?s)?(@\w*)?(\[)',
                bygroups(Name.Function,
                    Keyword.Pseudo,
                    Name.Variable,
                    Text),
                'web_element'),

            (r'\b(xpath)(:all|:try|:try[\dX]+m?s?|:wait[\dX]+m?s)?(@\w*)?(\[)(.*?)(\])',
                bygroups(Name.Function,
                    Keyword.Pseudo,
                    Name.Variable,
                    Text,
                    String,
                    Text)),

            (r'\b(link)(:fragment|:try|:try[\dX]+m?s?|:wait[\dX]+m?s)?(@\w*)?(\[)(.*?)(\])',
                bygroups(Name.Function,
                    Keyword.Pseudo,
                    Name.Variable,
                    Text,
                    String,
                    Text)),

            (r'\b(links)(:fragment)?(@\w*)?(\[)(.*?)(\])',
                bygroups(Name.Function,
                    Keyword.Pseudo,
                    Name.Variable,
                    Text,
                    String,
                    Text)),

            (r'\b(tag|button|input|field|h[1-6]|legend|span)(:try|:try[\dX]+m?s?|:wait[\dX]+m?s)?(@\w*)?(\[)(.*?)(\])',
                bygroups(Name.Function,
                    Keyword.Pseudo,
                    Name.Variable,
                    Text,
                    String,
                    Text)),

            (r'\b(tags)(@\w*)?(\[)(.*?)(\])',
                bygroups(Name.Function,
                    Name.Variable,
                    Text,
                    String,
                    Text)),

            (r'\b(web)(\[\])',
                bygroups(Name.Function,
                    Text)),

            (r'\b(js)(:value)?(@\w+)?(\{)',
                bygroups(Name.Function,
                    Keyword.Pseudo,
                    Name.Variable,
                    Text),
                'js_code'),

            (r'\b(js)(:file)(\[)(.*?)(\])',
                bygroups(Name.Function,
                    Keyword.Pseudo,
                    Text,
                    String,
                    Text)),

            (r'\$\w+', 
                Name.Function),

            (r'@\w*', 
                Name.Variable),

            (r'#\w+', 
                Name.Variable.Global),

            (r'#',
                Name.Variable),

            (r'(:)(not|alive|ignore|ajax|[\dX]+m?s|alt|ever|[\dX]+times|reverse|max[\dX]+|min[\dX]+|all|fragment|try[\dX]+m?s|try|wait[\dX]+m?s)\b',
                bygroups(Keyword.Pseudo,
                    Keyword.Pseudo)),

            (r'\b(\d+)(\.\d+)?\b',
                Number),

            (r'(//.*?//|/:.*?:/|/\$.*?\$/|/".*?"/)(\w*)', 
                bygroups(String.Regex,
                    String.Symbol)),

            (r'\b(sessions|windows|tabs|cookies|alert|tabs|css|xpath|links?|tags?|button|input|field|web|h[1-6]|legend|span)\b',
                Name.Variable.Global),

            (r'\w+', Name.Property),

            (r'"',
                String,
                'string'),

            (r'`(``.*?```|`.*?$|.*?`)', 
                Comment),

            (r'.', Text)
        ],

        'string': [
            
            (r'\\.',
                String.Escape),

            (r'"', 
                String, 
                '#pop'),

            (r'.', String)
        ],

        'sql_code': [

            (r'\b(SELECT|FROM|WHERE|LIMIT|INSERT|INTO|VALUE)\b',
                Keyword),

            (r'@:[\w\_]+',
                Name.Variable),

            (r'#:[\w\_]+',
                Name.Variable.Global),

            (r'([\w\_]+)(\s*\()',
                bygroups(Name.Function,
                    Text)),

            (r'\d+(\.\d+)?',
                Number),

            (r'}',
                Text,
                '#pop'),

            (r'.', Text)
        ],

        'web_element': [

            (r'\.[\w\-\_]+',
                Name.Class),

            (r'#[\w\-\_]+',
                Name.Variable.Instance),

            (r'(\:[\w\-\_]+)(\s*\()',
                bygroups(Name.Function,
                    Text)),

            (r'\:[\w\-\_]+',
                Name.Property),

            (r'\b([\w\-\_]+)(=[^\w]?)([\w\-\_]+)',
                bygroups(Name.Attribute,
                    Text,
                    String)),

            (r'\b\d+(\.\d+)?\b',
                Number),

            (r'\b[\w\-\_]+\b',
                Keyword.Type),

            (r'\[',
                Text,
                '#push'),

            (r'\]',
                Text,
                '#pop'),

            (r'.', Text)
        ],

        'js_code': [

            (r'\b(abstract|arguments|await|boolean|break|byte|case|catch|char|class|const|continue|debugger|default|delete|do|double|else|enum|eval|export|extends|false|final|finally|float|for|function|goto|if|implements|import|in|instanceof|int|interface|let|long|native|new|null|package|private|protected|public|return|short|static|super|switch|synchronized|this|throw|throws|transient|true|try|typeof|var|void|volatile|while|with|yield)\b',
                Keyword),

            (r'\$\{[\w\_]+\}',
                Name.Function),

            (r'(\.)([\w\_]+)(\s*\()',
                bygroups(Text,
                    Name.Function,
                    Text)),

            (r'(\.)([\w\_]+)',
                bygroups(Text,
                    Name.Property)),

            (r'\b(window|document|crossfire)\b',
                Name.Variable.Global),

            (r'"',
                String,
                'string'),

            (r'\{',
                Text,
                '#push'),

            (r'\}',
                Text,
                '#pop'),

            (r'.', Text)
        ]
    }
