from transformers import ViTImageProcessor, ViTModel
import torch
from PIL import Image

def vit_inference_fp16():
    # ViT 모델 및 이미지 프로세서 로드
    model = ViTModel.from_pretrained("google/vit-base-patch16-224-in21k").cuda()
    processor = ViTImageProcessor.from_pretrained("google/vit-base-patch16-224-in21k")

    # 기본 흰색 이미지 생성
    image = Image.new("RGB", (224, 224), color="white")

    # 이미지 전처리
    inputs = processor(images=image, return_tensors="pt")
    inputs = {key: value.cuda() for key, value in inputs.items()}

    # FP16 추론
    with torch.no_grad():
        with torch.cuda.amp.autocast():  # FP16 연산 활성화
            outputs = model(**inputs)

    # 결과 출력
    print("Last Hidden State Shape:", outputs.last_hidden_state.shape)

if __name__ == "__main__":
    vit_inference_fp16()
