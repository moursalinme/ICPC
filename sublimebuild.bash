{
 
 "cmd":["g++ -std=c++17 -D LOCAL=1 -Wshadow -Wall $file_name -o $file_base_name -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG && timeout 5s ./$file_base_name"],
 
 "quiet": false ,
 
 "shell": true ,
 
 "working_dir": "${file_path}",
 
 "selector": "source.c++"
}
