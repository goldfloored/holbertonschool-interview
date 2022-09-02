#!/usr/bin/python3
# this module prints useful log info every 10 lines received from stdin

if __name__ == "__main__":
    from sys import stdin
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404:
                    0, 405: 0, 500: 0}
    file_size, count = 0, 0

    def print_data(status_codes, file_size):
        ''' print file size and status codes '''
        print("File size: {}".format(file_size))
        for k in sorted(status_codes.keys()):
            if status_codes[k] > 0:
                print("{}: {}".format(k, status_codes[k]))
    try:
        for line in stdin:
            try:
                data = line.split()
                status_code = int(data[-2])

                if status_code in status_codes:
                    status_codes[status_code] += 1
            except BaseException:
                pass
            try:
                file_size += int(data[-1])
            except BaseException:
                pass

            count += 1
            if count % 10 == 0:
                print_data(status_codes, file_size)

    except KeyboardInterrupt:
        print_data(status_codes, file_size)
        raise

    print_data(status_codes, file_size)