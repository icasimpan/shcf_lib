### -------------------------------------------------------
### get_daynum: Translates the day name using either %u or
###               %w of 'date'.
### INPUT  : $1 - day number
###          $2 - format, 'u' or 'w'
### OUTPUT :  'Mon'..'Sun'
### -------------------------------------------------------

get_daynum() {
    local this_day=$1
    local use_format=$(echo $2|tr A-Z a-z) ## 2 formats supported. %u and %w
                                           ## difference between the two is
                                           ## only the representation of 'Sun'
                                           ##   %u - 7
                                           ##   %w - 0
    local day_num=""

    [[ "$use_format" = "u" ]] && [[ "$this_day" = "Sun" ]] && day_num=7
    [[ "$use_format" = "w" ]] && [[ "$this_day" = "Sun" ]] && day_num=0

    case $this_day in
      Mon)
        day_num=1
      ;;
      Tue)
        day_num=2
      ;;
      Wed)
        day_num=3
      ;;
      Thu)
        day_num=4
      ;;
      Fri)
        day_num=5
      ;;
      Sat)
        day_num=6
      ;;
    esac

    echo "$day_num"

} ## END: get_daynum()
