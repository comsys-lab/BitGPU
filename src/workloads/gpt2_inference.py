from transformers import GPT2Tokenizer, GPT2Model
import torch

def gpt2_inference_fp16():
    # GPT-2 모델 및 토크나이저 로드
    tokenizer = GPT2Tokenizer.from_pretrained("gpt2")
    model = GPT2Model.from_pretrained("gpt2").cuda()

    # 입력 데이터 준비
    text = "The future of AI is"
    inputs = tokenizer(text, return_tensors="pt")
    inputs = {key: value.cuda() for key, value in inputs.items()}

    # FP16 추론
    with torch.no_grad():
        with torch.cuda.amp.autocast():  # FP16 연산 활성화
            outputs = model(**inputs)

    # 결과 출력
    print("Last Hidden State Shape:", outputs.last_hidden_state.shape)
    print("Last Hidden State Sample Values:", outputs.last_hidden_state[0][0][:5])

if __name__ == "__main__":
    gpt2_inference_fp16()
