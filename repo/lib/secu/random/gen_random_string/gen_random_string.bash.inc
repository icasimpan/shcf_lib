gen_random_string() {
  date | sha1sum | cut -d' ' -f1 
}
