### -------------------------------------------------------
### get_dayname: Translates the day name using either %u or
###               %w of 'date'.
### INPUT  : $1 - day number
###          $2 - format, 'u' or 'w'
### OUTPUT :  'Mon'..'Sun'
### -------------------------------------------------------

get_dayname() {
    local this_day=$1
    local use_format=$(echo $2|tr A-Z a-z) ## 2 formats supported. %u and %w
                                           ## difference between the two is
                                           ## only the representation of 'Sun'
                                           ##   %u - 7
                                           ##   %w - 0
    local day_name=""

    [[ "$use_format" = "u" ]] && [[ $this_day -eq 7 ]] && day_name='Sun'
    [[ "$use_format" = "w" ]] && [[ $this_day -eq 0 ]] && day_name='Sun'

    case $this_day in
      1)
        day_name='Mon'
      ;;
      2)
        day_name='Tue'
      ;;
      3)
        day_name='Wed'
      ;;
      4)
        day_name='Thu'
      ;;
      5)
        day_name='Fri'
      ;;
      6)
        day_name='Sat'
      ;;
    esac

    echo "$day_name"

} ## END: get_dayname()
