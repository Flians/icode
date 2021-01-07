#!/bin/sh

git filter-branch --env-filter '
CORRECT_NAME="Flians"
CORRECT_EMAIL="rongliangfu@outlook.com"

if [ "$GIT_COMMITTER_EMAIL" != "$CORRECT_NAME" ]
then
    export GIT_COMMITTER_NAME="$CORRECT_NAME"
    export GIT_COMMITTER_EMAIL="$CORRECT_EMAIL"
fi
if [ "$GIT_AUTHOR_EMAIL" != "$CORRECT_NAME" ]
then
    export GIT_AUTHOR_NAME="$CORRECT_NAME"
    export GIT_AUTHOR_EMAIL="$CORRECT_EMAIL"
fi
' --tag-name-filter cat -- --branches --tags


git push --force --tags origin 'refs/heads/*'