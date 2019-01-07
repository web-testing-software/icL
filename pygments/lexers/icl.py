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
            (r'\b(if|else|for|filter|range|exists|while|do|any|emit|emiter|slot|assert|listen|wait|jammer|switch|case|SELECT|FROM|WHERE|LIMIT|INSERT|INTO|VALUE)\b', Keyword),
            (r'\b(bool|int|double|string|list|element|set|item|object|function|void|request|char|regex|datetime)\b', Keyword.Type),
            (r'(\[)(icL|w3c)(\])', bygroups(Operator.Word, Name.Label, Operator.Word)),
            (r'\b(icL|Log|Tab|Doc|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies?|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|States|DB|Query|DBManager|Code|Signal|Datetime)\b', Name.Class),
            (r'\'[\w\-\*]+', Name.Property),
            (r'\.\w+', Name.Function),
            (r'\b(Exit|NoSessions|NoSuchWindow|NoSuchElement|NoSuchFrame|NoSuchCookie|NoSuchAlert|NoSuchPlaceholder|NoSuchDatabase|NoSuchServer|WrongUserPassword|StaleElementReference|FolderNotFound|FileNotFound|FieldNotFound|FieldAlreadyExists|OutOfBounds|UnsupportedOperation|EmptyString|EmptyList|MultiList|EmptyElement|MultiElement|EmptySet|MultiSet|InvalidArgument|InvalidSelector|InvalidElementState|InvalidElement|IncompatibleRoot|IncompatibleData|IncompatibleObject|InvalidSessionId|InvalidCookieDomain|InsecureCertificate|UnexpectedAlertOpen|UnrealCast|ParsingFailed|WrongDelimiter|ComplexField|ElementNotInteractable|ElementClickIntercepted|MoveTargetOutOfBounds|UnableToSetCookie|UnableToCaptureScreen|JavascriptError|ScriptTimeout|Timeout|SessionNotCreated|QueryNotExecutedYet|UnknownCommand|UnknownError|UnknownMethod)\b', Name.Exception),
            (r'".*?"', String),
            (r'\b(css(:all)?|xpath(:all)?|links?(:fragment)?|tags?)(@\w*)?\[.*?\]', Name.Tag),
            (r'/(/.*?/|:.*?:|\$.*?\$)/\w*', String.Regex),
            (r'`(``.*?```|`.*?$|.*?`)', Comment),
            (r'\$(value|run|runAsync|user|file|always)', Name.Attribute),
            (r'@(\{\w+\}|:\w+|\w*)', Name.Variable),
            (r'#(\{\w+\}|:\w+|\w+)', Name.Variable.Global),
            (r'#|~', Name.Variable),
            (r'\d+(\.\d+)?', Number)
        ]
    }
