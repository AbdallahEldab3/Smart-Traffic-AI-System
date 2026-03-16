import argparse
import cv2

from traffic import TrafficDetector
from parked import ParkingDetector
from wrong_way import TrafficDetector as WrongWayDetector


def run_traffic(source):
    detector = TrafficDetector()

    if source.isdigit():
        detector.cap = cv2.VideoCapture(int(source))
    else:
        detector.cap = cv2.VideoCapture(source)

    while True:
        frame = detector.get_processed_frame()
        if frame is None:
            continue

        cv2.imshow("Traffic AI System", frame)

        if cv2.waitKey(1) & 0xFF == 27:
            break

    detector.cap.release()
    cv2.destroyAllWindows()


def run_parking(source, output):
    detector = ParkingDetector()
    detector.process_video(source, output)


def run_wrong_way(source, output):
    detector = WrongWayDetector()
    detector.process_video(source, output)


def main():
    parser = argparse.ArgumentParser(description="Smart Traffic AI Inference")

    parser.add_argument(
        "--mode",
        type=str,
        required=True,
        choices=["traffic", "parking", "wrongway"],
        help="Select detection system"
    )

    parser.add_argument(
        "--source",
        type=str,
        default="0",
        help="Video source (0 for webcam, path, or RTSP)"
    )

    parser.add_argument(
        "--output",
        type=str,
        default="output.mp4",
        help="Output video path"
    )

    args = parser.parse_args()

    if args.mode == "traffic":
        run_traffic(args.source)

    elif args.mode == "parking":
        run_parking(args.source, args.output)

    elif args.mode == "wrongway":
        run_wrong_way(args.source, args.output)


if __name__ == "__main__":
    main()