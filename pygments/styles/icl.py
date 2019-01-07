from pygments.style import Style
from pygments.token import Keyword, Name, Comment, String, Error, \
     Number, Operator, Generic, Whitespace


class IclStyle(Style):

    default_style = ''

    styles = {
        Whitespace:             '#000000',
        Comment:                '#808080',
        Comment.Preproc:        '#808080',
        Comment.Special:        '#808080',

        String:                 '#6700b6',
        String.Regex:           '#8900b6',
        String.Other:           '#6700b6',
        String.Symbol:          '#6700b6',
        String.Interpol:        '#6700b6',
        String.Escape:          '#8900b6',

        Operator.Word:          '#232323',

        Keyword:                '#f60000',
        Keyword.Pseudo:         '#1300b6',
        Keyword.Type:           '#0055ee',

        Name.Class:             '#fa5000',
        Name.Exception:         'bg:#ebfa00 #232323',
        Name.Function:          '#03945e',
        Name.Property:          '#45816b',
        Name.Namespace:         '#45816b',
        Name.Builtin:           '#03945e',
        Name.Variable:          '#131560',
        Name.Variable.Class:    '#5c5d83',
        Name.Variable.Instance: '#5c5d83',
        Name.Variable.Global:   '#446c03',
        Name.Constant:          '#5c5d83',
        Name.Tag:               '#0e84b5',
        Name.Attribute:         '#ac3333',
        Name.Decorator:         '#5c5d83',
        Name.Label:             'bold #ac3333',

        Number:                 '#ac3333',

        Generic.Heading:        '#232323',
        Generic.Subheading:     '#232323',
        Generic.Deleted:        '#232323',
        Generic.Inserted:       '#232323',
        Generic.Error:          '#232323',
        Generic.Emph:           '#232323',
        Generic.Strong:         '#232323',
        Generic.Prompt:         '#232323',
        Generic.Output:         '#232323',
        Generic.Traceback:      '#232323',

        Error:                  '#232323'
    }
 
