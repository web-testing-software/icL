# About standards

I have planned to write the standard for language icL in 2 languages:
engish and russian.

# Requests

 * [?] - a new request
 * [!] - an approved request
 * [+] - a released request

__18.09.2018__

 * [+] Rename _tab.get -&gt; _tab.load.
 * [+] Add new method _tab.get, which doesn't generate signals, just return
   true on success otherwise false.
 * [+] Remove _stacks'(int).
 * [+] Remove _stacks.if.
 * [+] Remove _stacks.ifexists.
 * [+] Remove _stacks.loop.
 * [+] Remove _stacks.while.
 * [+] Remove _stacks.dowhile.
 * [+] Remove _stacks.for.
 * [+] Remove _stacks.forany.
 * [+] Remove _stacks.range.
 * [+] Remove _stacks.filter.
 * [+] Change _stacks.break -&gt; aviable just for loops.
 * [+] Add _stack.return -&gt; especially for functions.
 * [+] Rename all System data types to first uppercase names and remove
   underline (_)
 * [+] Add States'first, States'last, States'next, States'prev : object, to get
   access to data, which can be important.

All approved changes will be applicated in Standard for icL RC 2.

__21-22.09.2018__

 * [+] Add comma delimiter beetwen grouped values, the list changes from
   [**"str1"** **"str2"** **"str3"**] to [**"str1"**, **"str2"**, **"str3"**].
 * [+] Change object field syntax from &lt;value&gt;name to name = value, the
   objects changes from [&lt;**23**&gt;*age* &lt;**"Alice"**&gt;*name*] to 
   [*age* = **23**, *name* = **"Alice"**], the empty object will look like [=].
 * [+] Change parameter syntax from &lt;type&gt;name to name : type, the set
   changes from [&lt;**int**&gt;*age* &lt;**string**&gt;*name*] to 
   [*age* : **int**, *name* : **string**], the empty set will look like [:].
 * [+] Change function syntax from !*name* = **params** : **type** {} to *name*
   = (**params**) : **type** {}, restict first upper case letter in function
   name, with the previous changes the function declaration will look like
   *func* = (*@arg1* : **int**, *@arg2* : **string**) : **string** {}.
 * [+] Change the function call syntax from !name args... to name (args..),
   beetwen arguments needs to be comma delimiter.
 * [+] Brackets may be skiped if the number of args is equal with **1**.
 * [+] Change the operator **&lt;&lt;** to **&lt;** and **&gt;&gt;** to
   **&gt;**.
 * [+] Add autofinish of commands.
 * [+] Now the underline (_) symbol can be used in variables names.
 * [+] Add datetime type (equivalent to QDateTime), with the next properties
   'year, 'month, 'day, 'hour, 'minut, 'second.
 * [+] Add Set.clone, Object.clone methods.
 * [+] Add type var define [**type**] === [**type** : **type**] and
   (**type**) === (**@type** : **type**), simplify set and functions headers.
 * [+] Add var field define [**@var**] === [**var** = **@var**], simplify
   object define. On multiple values [@var1, @var2] the expresion will be
   parsed like group operator, to elude conflicts add an empty parameter at
   the first position, like [=, @var1, @var2].
 * [+] Add packed values description.
 * [+] Add **m** : **1** operations, cast all variables in one type, etc.
 * [+] Add **1** : **m** operations, test cast in several types, etc.
 * [+] Add **m** : **m** operations, cast each variable in diferent type.
 * [+] Add default values for functiuons params.
 * [+] Rename **ICL** to **icL**, **DOM** to **Doc**.
 * [+] Add new operator **!&lt;**, inversion of **&lt;&lt;**.
 * [+] Add **~** sign, which permite to generate void object.
 * [+] Add default values to functions parameters, syntax func =
   (**@var** = **value**, **@var2** : **int**) {}, the default values must be 
   any, not just the last, the last default parameters can be skipped, to set 
   default value for non last parameter use void sign, example: func (~, 3) or
   func 3 (if all params are optional, excepting the last, the function can be
   called without curly brackets, indicating just the last argument).
 * [+] Add Stacks.root to get root stack, in function it's the function stack.
 * [+] Add explication for @ and # variables.

All approved changes will be applicated in Standard for icL RC 3.

__07.10.2018__

 * [+] Add new cast operator *:!* **cast now** with rang 7
 * [+] Add new cast operator *:?* **maybe cast** with rang 7, cast the value if
   posible, otherwise return void
 * [+] Replace , by ; in controls and loops
 * [+] Add switch-case control
 * [+] Improve wait mechanism
 * [+] Add element less input simulation
 * [+] Add force input methods
 * [+] Add DB client connection
 * [+] Expand reverse keyword
 * [+] Replace insertBoolField, insertIntField, insertDoubleField,
   insertStringField and insertListField by insertField method
 * [+] Remove Stacks.root method.
 * [+] Add Stack.return, Stack.continue and Stack.break compatible stack search
 * [!] Add Stack.markTest and Stack.markStep
 * [!] Fix include policy
 * [+] Add errorless programing section, with the next errorless constructions
   * [+] **~**.anyMethod (any args) : **void**
   * [+] **~**'anyProperty : **void**
   * [+] value.anyMethod **~** : **void**

All approved changes will be applicated in Standard for icL RC 4.
