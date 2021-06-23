
# easystring
C++ Single-header library containing simple string utilities.

# usage
All you gotta do is include the header file in your code. No compilation needed.  
You can place the file directly next to your source, or configure some sort of include path for your project, it's up to you.

For ease of use, I'd use the following line:
`namespace es = easystring;`
This lets you shorten your lines a lot, for example `es::split` vs `easystring::split` makes a difference.

# functions

### `es::uppercase(string) -> string`
Makes the string uppercase.

### `es::lowercase(string) -> string`
Makes the string lowercase.

### `es::pad_left(string, character, amount) -> string`
Adds `amount` of `character` to the left of the string.

### `es::pad_right(string, character, amount) -> string`
Adds `amount` of `character` to the right of the string.

### `es::title_case(string) -> string`
Turns the string into title case, ex. "hello wORLD!" -> "Hello World"

### `es::split(string, delimiter) -> vector<string>`
Splits the string into a vector of strings, using the delimiter.
For example:
`es::split("Hello::world()", "::") -> ["Hello", "world()"]`

### `es::left_justify(string, character, length) -> string`
Left-pads the string with `character` until the whole string reaches the specified `length`.
This is useful when you want to align things in the console.

### `es::right_justify(string, character, length) -> string`
Same thing as `left_justify`, but adds the characters on the right instead.

### `es::trim_left(string) -> string`
Removes all whitespace from the left of the string.

### `es::trim_right(string) -> string`
Removes all whitespace from the right of the string.

### `es::trim(string) -> string`
Removes all leading and trailing whitespace from the string.

### `es::reverse(string) -> string`
Reverses a string (duh).

### `es::starts_with(string, prefix) -> boolean`
Returns `true` if the string starts with the specified prefix.

### `es::ends_with(string, suffix) -> boolean`
Returns `false` if the string ends with the specified suffix.

### `es::contains(string, another string) -> boolean`
Returns `true` if the string contains the other one.

### `es::is_upper(string) -> boolean`
Returns `true` if all characters in the string are uppercase.

### `es::is_lower(string) -> boolean`
Returns `true` if all characters in the string are lowercase.

### `es::replace(string, from, to) -> string`
Replaces all occurences of `from` with `to` in the string.
### `es::replace(string, map) -> string`
The map is supposed to be a `unordered_map` of strings to strings.
It will perform a replace on the `string` according to the map.