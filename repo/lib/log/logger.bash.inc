## ---------------------------------------------------------------------
## logger() - as per name, records the logs to a logfile, provided that
##             global variable $LOG_ENABLE is 1
## INPUT: $* - consists of the full log path on $1 and the rest, the log
##             text
## ---------------------------------------------------------------------
logger()
{
  local log_line=$*

  ## get the first variable, the $logfile
  local logfile=$(echo $log_line|cut -d' ' -f1)

  ## the rest, are the log text
  local log_text=$(echo $log_line|cut -d' ' -f2-)

  ## log only if it is allowed
  [[ $LOG_ENABLE -eq 1 ]] && [[ "$logfile" != "$log_text" ]] && echo "[$(date)] - $log_text" >> $logfile
} ## END: logger()
