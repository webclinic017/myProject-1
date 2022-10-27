if (($# == 0))
then
    echo "must give at least one parameter (the process name you want to kill)" # 参数检查
    exit
fi

#grep -v grep: 排除grep --color=auto这一条
#grep -v $0: 排除自己脚本 bash ./???.sh param1 param2 这一条

process_number=`ps -ef | grep "$*" | grep -v grep | grep -v $0 |wc -l`
if (($process_number == 0))
then
    echo "no such process now"
    exit
fi

for pid in `ps -ef | grep "$*" | grep -v grep | grep -v $0 | awk '{print $2}'`
do
    #检查得到的pid是否为数字
    if grep '^[[:digit:]]*$' <<< "$pid";then 
        echo "find process: \"$*\", pid = $pid, now is killed"
        kill -9 $pid
    else 
        echo "Wrong pid:\"$pid\"; pid is not number; maybe your linux command is wrong!"
    fi
done