### ----------------------------------------------------------
### get_jira_attrib: Gets specific attrib value from a jira
###
### INPUT  : $1 - jira number (e.g ISSUE-180)
###          $2 - attribute, supported are
###                  'parent'   - parent jira for a subtask
###                  'title'    - subject or title
###                  'reporter' - who created the jira
###                  'assignee' - who is currently working on the jira
###                  'status'   - if jira is 'Closed', 'In progress' etc.
### OUTPUT : <depends on $2 value>
### ----------------------------------------------------------

get_jira_attrib() {
  local jira_url=$1
  local ticket_id=$(echo $2|tr a-z A-Z)
  local attrib_name=$(echo $3|tr A-Z a-z)

  unset https_proxy ## very important. Otherwise, jira may not respond
  local retval=
  local jq_filter=

  local missing_attrib='_MISSING_'
  case $attrib_name in
      parent)
         jq_filter='.fields.parent.key'
      ;;
      title)
         jq_filter='.fields.summary'
      ;;
      reporter)
         jq_filter='.fields.reporter.name'
      ;;
      assignee)
         jq_filter='.fields.assignee.name'
      ;;
      status)
         jq_filter='.fields.status.name'
      ;;
      *)
         jq_filter=$missing_attrib
      ;;
  esac

  ## Make sure $attrib is NOT missing
  [[ "$jq_filter" != "$missing_attrib" ]] && {
         retval=$($CURL_BIN -k -s --config $CONF_DIR/auth/curl/jira.conf -X GET -H "Content-Type: application/json" $jira_url/rest/api/2/issue/$ticket_id 2>/dev/null | $JQ_BIN "$jq_filter" | $SED_BIN 's/\"//g')
  }

  echo $retval
} ## END: get_jira_attrib()
