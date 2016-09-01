### -------------------------------------------------
### month2days: outputs the number of days in a month,
###     given an input "mm yyyy". $INVALID on incorrect
###     month
### INPUT  : $1 - month
###          $2 - year
### OUTPUT : The number of days in the month or -1 if invalid
### -------------------------------------------------

month2days() {
  local month_in=$1   ## e.g. 06
  local year_in=$2    ## e.g. 2015

  ## list of functions to auto-load
  autoload_functions "common/is_leapyear"

  ## ...
  ## MAIN CODE...
  ## ...

  local retval=$INVALID   ## default invalid input

  ##
  ## 30 days in September, April, June, and November
  ##
  if [[ $month_in =~ 09|04|06|11 ]]; then
      retval="30"

  ##
  ## All the rest have 31 ==> Jan, Mar, May, Jul, Aug, Oct, Dec
  ##
  elif [[ $month_in =~  01|03|05|07|08|10|12 ]]; then
      retval="31"

  ##
  ## Feb is usually 28 days. Becomes 29 during leap year
  ##
  elif [[ "$month_in" = "02" ]]; then
    retval="28"
    [[ $(is_leapyear $year_in) -eq $TRUE ]] && retval="29"
  fi

  echo $retval
} ## END: month2days()
