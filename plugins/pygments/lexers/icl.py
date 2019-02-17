import re

from pygments.lexer import RegexLexer, bygroups
from pygments.token import *

__all__ = ['IclLexer']

class IclLexer(RegexLexer):
    name = 'icL'
    aliases = ['icl']
    filenames = ['*.icL']
    
    flags = re.MULTILINE | re.DOTALL

    tokens = {

        'root': [

            (r'\b(if|else|for|filter|range|exists|while|do|any|emit|emiter|slot|assert|listen|wait|jammer|switch|case)\b', 
                Keyword),
            
            (r'\b(bool|int|double|string|list|element|set|item|object|function|void|request|char|regex|datetime|any|type)\b', 
                Keyword.Type),
            
            (r'(\[)(icL|w3c)(\])', 
                bygroups(Text, 
                    Name.Label, 
                    Text)),

            (r'\b(icL|Log|Tab|Doc|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies?|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|State|DB|Query|DBManager|Code|Signal|Datetime)\b', 
                Name.Class),

            (r'\'[\w\-\*]+', 
                Name.Property),

            (r'(\.query)(\s*\{)',
                bygroups(Name.Function,
                    Text),
                'sql_code'),

            (r'\.\w+', 
                Name.Function),

            (r'\b(Exit|NoSessions|NoSuchWindow|NoSuchElement|NoSuchFrame|NoSuchCookie|NoSuchAlert|NoSuchPlaceholder|NoSuchDatabase|NoSuchServer|WrongUserPassword|StaleElementReference|FolderNotFound|FileNotFound|FieldNotFound|FieldAlreadyExists|OutOfBounds|UnsupportedOperation|EmptyString|EmptyList|MultiList|EmptyElement|MultiElement|EmptySet|MultiSet|InvalidArgument|InvalidSelector|InvalidElementState|InvalidElement|IncompatibleRoot|IncompatibleData|IncompatibleObject|InvalidSessionId|InvalidCookieDomain|InsecureCertificate|UnexpectedAlertOpen|UnrealCast|ParsingFailed|WrongDelimiter|ComplexField|ElementNotInteractable|ElementClickIntercepted|MoveTargetOutOfBounds|UnableToSetCookie|UnableToCaptureScreen|JavascriptError|ScriptTimeout|Timeout|SessionNotCreated|QueryNotExecutedYet|UnknownCommand|UnknownError|UnknownMethod)\b', 
                Name.Exception),

            (r'\b(css|xpath|links?|tags?)(:)(all|fragment)(@\w*)?(\[)', 
                bygroups(Name.Tag,
                    Keyword.Pseudo,
                    Keyword.Pseudo,
                    Name.Variable,
                    Text),
                'web_element'),

            (r'(\$)(value|run|runAsync)(\s*\{)',
                bygroups(Name.Attribute,
                    Name.Attribute,
                    Text),
                'js_code'),

            (r'\$(user|file|always)',
                Name.Attribute),

            (r'@\w*', 
                Name.Variable),

            (r'#\w+', 
                Name.Variable.Global),

            (r'#|~',
                Name.Variable),

            (r':\w+',
                Keyword.Pseudo),

            (r'\d+(\.\d+)?',
                Number),

            (r'(//.*?//|/:.*?:/|/\$.*?\$/|/".*?"/)(\w*)', 
                bygroups(String.Regex,
                    String.Symbol)),

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

            (r'\d+(\.\d+)?',
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

            (r'\b(window|document|crossfire)\b',
                Name.Variable.Global),

            (r'@\{[\w\_]*\}',
                Name.Variable),

            (r'#\{[\w\_]+\}',
                Name.Variable.Global),

            (r'\!\{[\w\_]+\}',
                Name.Function),

            (r'(\.)([\w\_]+)(\s*\()',
                bygroups(Text,
                    Name.Function,
                    Text)),

            (r'(\.)([\w\_]+)',
                bygroups(Text,
                    Name.Property)),

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
