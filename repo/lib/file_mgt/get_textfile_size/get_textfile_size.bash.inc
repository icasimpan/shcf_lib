## NOTE: As stated in http://stackoverflow.com/questions/5920333/how-to-check-size-of-a-file,
##       this may not work in OSX
get_textfile_size()
{
  local filename=$1
 
  echo $(wc -c < $filename)
} ## END: get_textfile_size()
