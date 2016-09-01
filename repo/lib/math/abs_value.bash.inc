### -------------------------------------------------
### abs_value: Gets math absolute value of common neg
###            number
### INPUT  : $1 - raw number
### OUTPUT : abs value
### -------------------------------------------------

abs_value() {
  local in_num=$1

  echo "$in_num"|sed 's/-//'
} ## END: abs_value()
