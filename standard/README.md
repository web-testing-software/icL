# About standards

I have planned to write the standard for language icL in 3 languages:
engish, russian and moldavian.

# Requests

__18.09.2018__

 * [+] Rename _tab.get -> _tab.load.
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
 * [+] Change _stacks.break -> aviable just for loops.
 * [+] Add _stack.return -> especially for functions.
 * [+] Rename all System data types to first uppercase names and remove
   underline (_)
 * [/] Add States'first, States'last, States'next, States'prev : object, to get
   access to data, which can be important.

All approved changes will be applicated in Standard for icL RC 2.

__21-22.09.2018__

 * [/] Add comma delimiter beetwen grouped values, the list changes from
   [**"str1"** **"str2"** **"str3"**] to [**"str1"**, **"str2"**, **"str3"**].
 * [/] Change object field syntax from <value>name to name = value, the objects
   changes from [<**23**>*age* <**"Alice"**>*name*] to [*age* = **23**, *name*
   = **"Alice"**], the empty object will look like [=].
 * [/] Change parameter syntax from <type>name to name : type, the set changes
   from [<**int**>*age* <**string**>*name*] to [*age* : **int**, *name* :
   **string**], the empty set will look like [:].
 * [/] Change function syntax from !*name* = **params** : **type** {} to *name*
   = (**params**) : **type** {}, restict first upper case letter in function
   name, with the previous changes the function declaration will look like
   *func* = (*@arg1* : **int**, *@arg2* : **string**) : **string** {}.
 * [/] Change the function call syntax from !name args... to name (args..),
   beetwen arguments needs to be comma delimiter.
 * [/] Brackets may be skiped if the number of args is equal with **1**.
 * [/] Change the operator **<<** to **<** and **>>** to **>**.
 * [/] Add autofinish of commands.
 * [/] Now the underline (_) symbol can be used in variables names.
 * [/] Add datetime type (equivalent to QDateTime), with the next properties
   'year, 'month, 'day, 'hour, 'minut, 'second.
 * [/] Add Set.clone method.
 * [/] Add type var define [**type**] === [**type** : **type**] and
   (**type**) === (**@type** : **type**), simplify set and functions headers.
 * [/] Add **m** : **1** operations, cast all variables in one type, etc.
 * [/] Add **1** : **m** operations, test cast in several types, etc.
 * [/] Add **m** : **m** operations, cast each variable in diferent type.
 * [/] Add default values for functiuons params.
 * [/] Rename **ICL** to **icL**, **DOM** to **Doc**.
 * [/] Add new operator **!<**, inversion of **<<**.
 * [/] Add **~** sign, which permite to generate void object.
 * [/] Add default values to functions parameters, syntax func =
   (**@var** = **value**, **@var2** : **int**) {}, the default values must be 
   any, not just the last, the last default parameters can be skipped, to set 
   default value for non last parameter use void sign, example: func (~, 3).

All approved changes will be applicated in Standard for icL RC 3.
