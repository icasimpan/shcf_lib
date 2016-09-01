### -------------------------------------------------
### tab2spaces: simulate inline 'expand' command via
###      temp file
### INPUT  : $1 - txtfile
###          $2 - numspace_per_tab [defaults to 4]
### OUTPUT : return 0 ($SUCCESS)
###                 1 ($FAILED)
### -------------------------------------------------

tab2spaces() {
  local txtfile=$1           ## must be fullpath
  local numspace_per_tab=$2

  ## implement default 4 spaces per tab
  [[ "$numspace_per_tab" = "" ]] && numspace_per_tab=4

  ## ..................
  ## main function code
  ## ..................

  retval=$FAILED
  ## $txtfile should be found. Otherwise, return error
  [[ ! -e $txtfile ]] && {
    local clean_file=$(mktemp)
    expand -t $numspace_per_tab > $clean_file
    [[ $? -gt 0 ]] && mv $clean_file $txtfile
    rm $clean_file
    retval=$SUCCESS
  }

  return $retval
} ## END: tab2spaces()
