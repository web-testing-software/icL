from pygments.style import Style
from pygments.token import Keyword, Name, Comment, String, Error, \
     Number, Operator, Generic, Whitespace


class IcldarkStyle(Style):

    default_style = '#f2f2f2'

    styles = {
        Whitespace:             '#ffffff',
        Comment:                '#9f8da6', 
        Comment.Preproc:        '#9f8da6',
        Comment.Special:        '#9f8da6',

        String:                 '#db69fe',
        String.Regex:           '#db69fe',
        String.Other:           '#db69fe',
        String.Symbol:          '#db69fe',
        String.Interpol:        '#db69fe',
        String.Escape:          '#db69fe',

        Operator.Word:          '#f2f2f2',

        Keyword:                '#ffff00',
        Keyword.Pseudo:         '#0084ff',
        Keyword.Type:           '#4a8bff',

        Name.Class:             '#faa162',
        Name.Exception:         'bg:#7f8600 #f2f2f2',
        Name.Function:          '#05f199',
        Name.Property:          '#69f1bf',
        Name.Namespace:         '#69f1bf',
        Name.Builtin:           '#05f199',
        Name.Variable:          '#e2ff57',
        Name.Variable.Class:    '#9698d6',
        Name.Variable.Instance: '#fd5584',
        Name.Variable.Global:   '#8ee827',
        Name.Constant:          '#9fa2e3',
        Name.Tag:               '#35b9ef',
        Name.Attribute:         '#ff5d5d',
        Name.Decorator:         '#fd5584',
        Name.Label:             'bold #ff5d5d',

        Number:                 '#ff5d5d',

        Generic.Heading:        '#f2f2f2',
        Generic.Subheading:     '#f2f2f2',
        Generic.Deleted:        '#f2f2f2',
        Generic.Inserted:       '#f2f2f2',
        Generic.Error:          '#f2f2f2',
        Generic.Emph:           '#f2f2f2',
        Generic.Strong:         '#f2f2f2',
        Generic.Prompt:         '#f2f2f2',
        Generic.Output:         '#f2f2f2',
        Generic.Traceback:      '#f2f2f2',

        Error:                  '#f2f2f2'
    }
 
