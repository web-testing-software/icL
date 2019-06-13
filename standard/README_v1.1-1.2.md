# About standards

I have planned to write the standard for language icL in 3 languages:
moldavian, engish and russian.

# Requests

 * [?] - a new request
 * [!] - an approved request
 * [+] - a released request

__24.12.2018__

* [?] Add literal for dates ./date./.format/.
* [+] Add literal for web elements:
  * [?] #[#element]
  * [?] @[.class]
  * [+] css[el]
  * [+] css:all[els]
  * [+] xpath[el]
  * [+] xpath:all[els]
  * [+] link[]
  * [+] link:fragment[]
  * [+] links[]
  * [+] links:fragment[]
  * [+] tag[]
  * [+] tags[]

All accepted changes will be present in version 1.1.0.

__14.01.2019__

* [?] Add literal for date [:date]
* [?] Add literal for date [::date ::format]
* [+] set.remove (obj : object) : set, add exception IncompatibleData
* [+] set.insertField (name : string, value : list, type = string), fix default
  argument name and add return type
* [+] add string.toLowerCase and string.toUpperCase
* [!] Add the next methods and properties
  * [+] Alert'session : session
  * [+] Cookies.new () : cookie
  * [+] doc'tab : tab
  * [+] element'doc : doc
  * [+] cookie'cookies : Cookies
  * [+] cookies'tab : tab
  * [+] session'alert : Alert
  * [+] session'tabs : Tabs
  * [+] session'windows : Windows
  * [+] Sessions'current : session
  * [+] tab'cookies : Cookies
  * [+] tab'doc : Doc
  * [+] tab'window : window
  * [!] Tabs'session : session
  * [+] tab'tabs : Tabs
  * [!] Tabs.get (i : int) : tab
  * [!] window'tab : tab
  * [!] window'windows : Windows
  * [!] Windows'session : session
* [!] Remove window.switchToDefault
* [!] Remove State'first, State'prev, State'next and State'last
* [!] Add double ** int operator
* [!] Fix switch-case syntax
* [!] Add literals input[name] and button[template]

All accpted changes will be present in version 1.2
