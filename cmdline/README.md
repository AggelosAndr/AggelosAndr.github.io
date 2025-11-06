# AggelosAndr.github.io
# Solutions for Bytes 1-15
**byte1:** Used `man` and `head` to examine the shell script `supercalifragilisticexpialidocious` and found the hidden string in the manual page.
**byte2:** Used `grep` to search for the phrase "will find" in `shakespeare.txt` and retrieved the hidden string.
**byte3:** Compared `shakespeare.txt` and `shakespeare.modified.txt` using `diff` to find the modified word.
**byte4:** Used `find` to locate `cup.txt` inside a complex folder structure and read its contents to get the secret.
**byte5:** Created a temporary folder in `/tmp`, copied `byte5.c`, compiled it with `gcc`, ran the program with a valid argument format, and obtained the key.
**byte6:** Copied `byte6.zip` to `/tmp`, unzipped it using `unzip`, and read `byte6.txt` to get the hidden string.
**byte7:** Copied `byte7.tar.gz` to `/tmp`, extracted it with `tar -xzf`, and read `byte7.txt` for the secret.
**byte8:** Examined `carriage_return.txt` with `xxd` to reveal hidden characters and recovered the secret string.
**byte9:** Used `cat ./-` to read a strangely named file (`-`) in `/home/byte9` to retrieve the secret.
**byte10:** Sorted `names.txt` alphabetically with `sort` and used `sed -n '42p'` to find the 42nd name.
**byte11:** Sorted `births.txt` and used `uniq -c` to count occurrences, then `sort -nr | head -n 1` to find the most frequent name.
**byte12:** Used `which tuxsay` to find the full path and `basename $(dirname …)` to get the folder name containing the program.
**byte13:** Entered the `repo` directory and used `git log --oneline` to read commit messages.
**byte14:** Checked `git log -p` to see all past diffs; confirmed that any secret the AI added was removed in a later commit.
**byte15:** Executed the `vault` program with a brute-force approach for the PIN, discovered it was `1337`, and obtained the secret.