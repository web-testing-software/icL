# About standards

I have planned to write the standard for language icL in 3 languages:
moldavian, engish and russian.

## Requests

* [?] - a new request
* [!] - an approved request
* [+] - a released request

### 09.06.2019

* [!] New level of code integration:
  * [!] `js{}` - JavaScript code
  * [!] `sql{}` - SQL code
  * [!] `icl{}` - icL code is the same language
  * [!] `icl:pro{}` - icL code in the icL Pro language
* [!] JavaScript refactoring:
  * [!] `$value {..}` → `js:value{..}`
  * [!] `$run {..}` → `js{..}.run()`
  * [!] `$run {..}` → `js{..}.run(doc)`
  * [!] `$file ".."` → `js:file[..].run()`
  * [!] `$user ".."` → `js:file[..].setAsUserScript()`
  * [!] `$always ".."` → `js:file[..].setAsPersistentUserScript()`
* [!] DataBase refactoring:
  * [!] `db.query {..}` → `db.query sql{..}`
  * [!] `db.query {..}` → `sql{..}.run(db)`
* [!] listen refactoring:
  * [!] `listen "server:port"` → `listen`
  * [!] `listen.handle(params)` → `handler`
  * [!] Add `handler.setup(code : icl)`
  * [!] Add `handler.activate()`
  * [!] Add `handler.deactivate()`
  * [!] Add `handler.kill()`
* [!] Remove:
  * [!] `Stack.destroy`
  * [!] `Stack.ignore`
  * [!] `Stack.listen`
  * [!] `*'canGoBack`
  * [!] `*'canGoForward`
* [!] Add:
  * [!] `doc.run(code : js) : any`
  * [!] `element'attrs-*`
  * [!] `element'props-*`
  * [!] `element'rects`
  * [!] `element'tags`
  * [!] `element'texts`
* [!] All element attributtes and properties get `r/o`
* [!] Add new element literals:
  * [!] `button[text]` - find button by text
  * [!] `input[name]` - find input by name
  * [!] `field[text]` - find input by label text
  * [!] `web[]` - return an empty element
  * [!] `h1-h6[text]` - returns a heading by text
  * [!] `span[text]` - returns a span by text
* [!] Add support for regex in element literals:
  * [!] `link[/regex/]`
  * [!] `button[/regex/]`
  * [!] `field[/regex/]`
  * [!] `h1-h6[/regex/]`
  * [!] `span[/regex/]`
* [!] Add new modifiers for sigle element literals:
  * [!] `:try` - don't generate a error on failed
  * [!] `:waitXs` - wait X seconds for, if not found throw a error
  * [!] `:waitXms` - wait X ms for, if not found throw a error
  * [!] `:tryXs` - wait X seconds for, after exit
  * [!] `:tryXms` - wait X ms for, after exit
* [!] `assert(.. , ..)` → `assert(.. ; ..)`

All approved requests will be applied in icL Pro 1.4
