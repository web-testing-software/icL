# -*- coding: utf-8 -*- #

module Rouge
  module Lexers
    class Icl < RegexLexer
      title     "icL"
      tag       'Icl'
      mimetypes 'text/x-icL'
      filenames '*.icL', '*.icL-Pro'

      state:root do
          rule /\b(now|if|else|for|filter|range|exists|while|do|any|emit|emiter|slot|assert|listen|wait|jammer|switch|case)\b/, Keyword
          rule /\b(bool|int|double|string|list|element|set|item|object|void|regex|datetime|session|window|cookie|tab|document|file|query|database|dbmanager|js-file|code-(icl|js|sql)|handler|any|type)\b/, Keyword::Type
          rule /\b(icL|Log|Tab|Document|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|State|DB|Query|DBManager|Code|Signal|Datetime)\b/, Name::Class
          rule /(\'[\w\-\*]+)/, Name
          rule /(sql)({)/ do
            groups Name::Function, Punctuation
            push :main__1
          end
          rule /(icl)(:pro)?({)/ do
            groups Name::Function, Keyword::Pseudo, Punctuation
          end
          rule /(\.\w+)/, Name::Function
          rule /\b(emit|slot)(:\w+)\b/ do
            groups Keyword, Keyword::Pseudo
          end
          rule /\b(css)(:all|:try|:try\d+m?s|:wait\d+m?s)?(@\w*)?(\[)/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation
            push :main__2
          end
          rule /\b(xpath)(:all|:try|:try\d+m?s|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(link)(:fragment|:try|:try\d+m?s|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(links)(:fragment)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(tag|button|input|field|h[1-6]|legend|span)(:try|:try\d+m?s|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(tags)(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(web)(\[\])/ do
            groups Name::Function, Punctuation
          end
          rule /\b(js)(:value)?(@\w+)?({)/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation
            push :main__3
          end
          rule /\b(js)(:file)(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Punctuation, String, Punctuation
          end
          rule /(\$\w+)/, Name::Function
          rule /(@\w+)/, Name::Variable
          rule /(#\w+)/, Name::Variable::Global
          rule /(#)/, Name::Variable
          rule /(:)(not|alive|ignore|ajax|\d+m?s|alt|ever|\d+times|reverse|max\d+|min\d+|all|fragment|try\d+m?s|try|wait\d+m?s)\b/ do
            groups Keyword::Pseudo, Keyword::Pseudo
          end
          rule /\b(\d+\.?\d*?)\b/, Number
          rule /(\/\/.*?\/\/|\/:.*?:\/|\/\$.*?\$\/|\/".*?"\/)(\w*)/ do
            groups String::Regex, String::Regex
          end
          rule /\b(sessions|windows|tabs|cookies|alert|tabs|css|xpath|links?|tags?|button|input|field|web|h[1-6]|legend|span)\b/, Generic::Error
          rule /(\")/, String, :main__4
          rule /(```)/, Comment, :main__5
          rule /(``)/, Comment, :main__6
          rule /(`)/, Comment, :main__7
          rule /(:\[)/, Punctuation, :main__8
          rule /(\[)/, Punctuation, :main__9
          rule /(;)/, Punctuation
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
          rule /\b(now|if|else|for|filter|range|exists|while|do|any|emit|emiter|slot|assert|listen|wait|jammer|switch|case)\b/, Keyword
          rule /\b(bool|int|double|string|list|element|set|item|object|void|regex|datetime|session|window|cookie|tab|document|file|query|database|dbmanager|js-file|code-(icl|js|sql)|handler|any|type)\b/, Keyword::Type
          rule /\b(icL|Log|Tab|Document|Import|true|false|Numbers|Types|Key|Alert|By|DSV|Sessions?|Windows?|Cookies|Tabs?|Files?|Make|Math|Wait|Mouse|Move|Stacks?|State|DB|Query|DBManager|Code|Signal|Datetime)\b/, Name::Class
          rule /(\'[\w\-\*]+)/, Name
          rule /(sql)({)/ do
            groups Name::Function, Punctuation
            push :main__1
          end
          rule /(icl)(:pro)?({)/ do
            groups Name::Function, Keyword::Pseudo, Punctuation
          end
          rule /(\.\w+)/, Name::Function
          rule /\b(emit|slot)(:\w+)\b/ do
            groups Keyword, Keyword::Pseudo
          end
          rule /\b(css)(:all|:try|:try\d+m?s|:wait\d+m?s)?(@\w*)?(\[)/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation
            push :main__2
          end
          rule /\b(xpath)(:all|:try|:try\d+m?s|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(link)(:fragment|:try|:try\d+m?s|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(links)(:fragment)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(tag|button|input|field|h[1-6]|legend|span)(:try|:try\d+m?s|:wait\d+m?s)?(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(tags)(@\w*)?(\[)(.*?)(\])/ do
            groups Name::Function, Name::Variable, Punctuation, String, Punctuation
          end
          rule /\b(web)(\[\])/ do
            groups Name::Function, Punctuation
          end
          rule /\b(js)(:value)?(@\w+)?({)/ do
            groups Name::Function, Keyword::Pseudo, Name::Variable, Punctuation
            push :main__3
          end
          rule /\b(js)(:file)(\[)(.*?)(\])/ do
            groups Name::Function, Keyword::Pseudo, Punctuation, String, Punctuation
          end
          rule /(\$\w+)/, Name::Function
          rule /(@\w+)/, Name::Variable
          rule /(#\w+)/, Name::Variable::Global
          rule /(#)/, Name::Variable
          rule /(:)(not|alive|ignore|ajax|\d+m?s|alt|ever|\d+times|reverse|max\d+|min\d+|all|fragment|try\d+m?s|try|wait\d+m?s)\b/ do
            groups Keyword::Pseudo, Keyword::Pseudo
          end
          rule /\b(\d+\.?\d*?)\b/, Number
          rule /(\/\/.*?\/\/|\/:.*?:\/|\/\$.*?\$\/|\/".*?"\/)(\w*)/ do
            groups String::Regex, String::Regex
          end
          rule /\b(sessions|windows|tabs|cookies|alert|tabs|css|xpath|links?|tags?|button|input|field|web|h[1-6]|legend|span)\b/, Generic::Error
          rule /(\")/, String, :main__4
          rule /(```)/, Comment, :main__5
          rule /(``)/, Comment, :main__6
          rule /(`)/, Comment, :main__7
          rule /(:\[)/, Punctuation, :main__8
          rule /(\[)/, Punctuation, :main__9
          rule /(;)/, Punctuation
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

