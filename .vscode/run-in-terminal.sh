#!/bin/zsh

set -euo pipefail

workspace_dir="${1:?Missing workspace directory}"
app_path="${workspace_dir}/build/app"

if [[ ! -x "${app_path}" ]]; then
    echo "Executable not found: ${app_path}" >&2
    exit 1
fi

shell_command="cd $(printf '%q' "${workspace_dir}") && $(printf '%q' "${app_path}"); printf '\\n'; read -n 1 -s -r -p 'Press any key to close...'; printf '\\n'; exit"
apple_script_command="${shell_command//\\/\\\\}"
apple_script_command="${apple_script_command//\"/\\\"}"

osascript <<APPLESCRIPT
tell application "Terminal"
    activate
    do script "${apple_script_command}"
end tell
APPLESCRIPT
